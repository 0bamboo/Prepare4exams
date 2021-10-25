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