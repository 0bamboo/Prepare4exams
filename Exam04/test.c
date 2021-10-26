#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int g_i;
int g_status = 0;
char **g_tab;

typedef enum s_type
{
	PIPE,
	END
} t_type;

t_type g_type;
t_type g_prevtype;
int ft_strlen(char *str);
int tab_len(char **tab);
void ft_putstr(char *str, int fd, int line);
void free_tab(char **tab);
char *ft_strdup(char *str);
char **push_tab(char **tab, char *str);
void cd_cmd();
int get_cmd(char **av);
int exec_cmd(char **env, int fd, int pipefd[2]);


int exec_cmd(char **env, int fd, int pipefd[2])
{
	pid_t pid;

	if (pipe(pipefd) == -1)
		ft_putstr("error: fatal", 2, 1);
	if ((pid = fork()) == -1)
		ft_putstr("error: fatal", 2, 1);
	else if (pid == 0)
	{
		if (dup2(fd, 0) == -1)
			ft_putstr("error: fatal", 2, 1);
		if (g_type == PIPE)
		{
			close(pipefd[0]);
			if (dup2(pipefd[1], 1) == -1)
				ft_putstr("error: fatal", 2, 1);
		}
		if (execve(g_tab[0], g_tab, env) != 0)
		{
			ft_putstr("error: cannot excute ", 2, 0);
			ft_putstr(g_tab[0], 2, 1);
		}
		exit(1);
	}
	else
	{
		close(pipefd[1]);
		if (g_type == END)
		{
			close(pipefd[0]);
			waitpid(pid, &g_status, 0);
			if (WIFEXITED(g_status))
				g_status = WEXITSTATUS(g_status);
			if (fd != 0)
				close(fd);
			fd = 0;
		}
		if (g_type == PIPE)
		{
			if (fd != 0)
				close(fd);
			fd = pipefd[0];
		}
	}
	return fd;
}

int main(int ac, char **av, char **env)
{
	int x, fd, pipefd[2];

	if (ac > 1)
	{
		g_i = 1;
		g_tab = malloc(sizeof(char *));
		g_tab[0] = NULL;
		g_prevtype = END;
		fd = 0;
		while ((x = get_cmd(av)))
		{
			if (g_tab[0] == NULL)
			{
				if ( x == 2)
					break;
			}
			else
			{
				if (!strcmp(g_tab[0], "cd") && g_prevtype != PIPE)
					cd_cmd();
				else
					fd = exec_cmd(env, fd, pipefd);
				free_tab(g_tab);
				if (x == 2)
					break;
				g_tab = malloc(sizeof(char *));
				g_tab[0] = NULL;
				g_prevtype = g_type;
			}
		}
	}
	return g_status;
}