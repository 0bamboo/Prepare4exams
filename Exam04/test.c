#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum s_type
{
	PIPE,
	END
}t_type;

int g_i;
int g_status = 0;
char **g_tab;

t_type g_prevtype;
t_type g_type;

int ft_strlen(char *str);
int tab_len(char **tab);
char *ft_strdup(char *str);
char **push_tab(char **tab, char *str);
void cd_cmd(void);
int get_cmd(char **av);
int exec_cmd(char **env, int fd, int pipefd[2]);
void free_tab(char **tab);
void ft_putstr(char *str, int fd, int line);


int tab_len(char **tab)
{
	int i = -1;
	while(tab[++i]);
	return i;
}

int ft_strlen(char *str)
{
	int i = -1;
	while (str[++i]);
	return i;
}

void ft_putstr(char *str, int fd, int line)
{
	int i = -1;
	while(str[++i])
		write(fd, &str[i], 1);
	if (line)
		write(fd, "\n", 1);
}

void free_tab(char **tab)
{
	int i =-1;
	while(tab[++i])
		free(tab[i]);
	free(tab);
}

char *ft_strdup(char *str)
{
	int i = -1;
	char *new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while(str[++i])
		new[i] = str[i];
	new[i] = 0;
	return new;
}


char **push_tab(char **tab, char *str)
{
	int i = -1;
	char **new = malloc(sizeof(char *) *(tab_len(tab) + 2));
	while(tab[++i])
		new[i] = ft_strdup(tab[i]);
	new[i++] = ft_strdup(str);
	free_tab(tab);
	return new;
}


int get_cmd(char **av)
{
	g_type = END;
	while (av[g_i])
	{
		if (!strcmp(av[g_i], "|"))
		{
			g_i++;
			g_type = PIPE;
			return 1;
		}
		else if (!strcmp(av[g_i], ";"))
		{
			g_i++;
			g_type = END;
			return 1;
		}
		g_tab = push_tab(g_tab, av[g_i]);
		g_i++;
	}
	return 2;
}

void cd_cmd(void)
{
	if (tab_len(g_tab) == 2)
	{
		if (chdir(g_tab[0]) != 0)
		{
			ft_putstr("cant move to ", 2, 0);
			ft_putstr(g_tab[0], 2, 1);
			g_status = 1;
		}
	}
	else
	{
		ft_putstr("wrong arg", 2, 1);
		g_status = 1;
	}
}

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
				if (x == 2)
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