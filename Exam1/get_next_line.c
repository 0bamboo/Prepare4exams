/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 15:49:10 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/17 14:12:20 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
#  define BUFFER_SIZE 1

size_t	ft_strlen(const char *s)
{
	size_t		j;

	j = 0;
	while (*s != '\0')
	{
		j++;
		s++;
	}
	return (j);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(s);
	if (!(tmp = (char *)malloc(len + 1)))
		return (0);
	while (i <= len)
	{
		tmp[i] = s[i];
		i++;
	}
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
	}
	if (c == '\0')
		return (p);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		j;
	char		*sub;

	if (!s || !(sub = (char *)malloc(len + 1)))
		return (NULL);
	if (start > len)
		return (ft_strdup(""));
	j = 0;
	while (j < len)
		sub[j++] = s[start++];
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		l;
	char	*join;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	l = i + j;
	if (!(join = (char *)malloc((l + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		join[i] = s2[j];
		i++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}


void		ft_cleanall(char **s_tab)
{
	if (s_tab && *s_tab)
	{
		free(*s_tab);
		*s_tab = NULL;
	}
}

int			ft_checkline(char **s_tab, char **line, int byt)
{
	int			i;
	char		*tmp2;

	i = 0;
	while (s_tab[0][i] != '\n' && s_tab[0][i] != '\0')
		i++;
	if (s_tab[0][i] == '\n')
	{
		free(*line);
		*line = ft_substr(*s_tab, 0, i);
		tmp2 = ft_strdup(*s_tab + i + 1);
		free(*s_tab);
		*s_tab = tmp2;
		if (s_tab[0][0] == '\0')
			ft_cleanall(s_tab);
	}
	else
	{
		free(*line);
		*line = ft_strdup(s_tab[0]);
		ft_cleanall(s_tab);
		if (!byt)
			return (0);
	}
	return (1);
}

int			ft_help(char **line, char **s_tab, int byt)
{
	if (line)
		*line = ft_strdup("");
	if (byt == -1)
		return (-1);
	else if (byt == 0 && !*s_tab)
		return (0);
	else
		return (ft_checkline(s_tab, line, byt));
}

int			get_next_line(int fd, char **line)
{
	static char		*s_tab;
	char			*buff;
	int				byt;

	if (fd < 0 || BUFFER_SIZE <= 0 ||
			!line || !(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (ft_help(line, &s_tab, -1));
	while ((byt = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byt] = '\0';
		if (s_tab == NULL)
			s_tab = ft_strdup(buff);
		else
			s_tab = ft_strjoin(s_tab, buff);
		if (ft_strchr(s_tab, '\n'))
			break ;
	}
	free(buff);
	return (ft_help(line, &s_tab, byt));
}
