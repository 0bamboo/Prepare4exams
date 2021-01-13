/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:44:59 by abdait-m          #+#    #+#             */
/*   Updated: 2020/12/19 17:50:27 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i++]);
    return (--i);
}

int is_n(char *s)
{
    while (*s)
    {
        if (*s == '\n')
            return (1);
        s++;
    }
    return (0);
}

char *ft_strdup(char *s)
{
    int len;
    int o;
    char *jadwallhorof;

    len = ft_strlen(s) + 1;
    if (!(jadwallhorof = malloc(sizeof(char) * len)))
        return (NULL);
    o = 0;
    while (s[o])
    {
        jadwallhorof[o] = s[o];
        o++;
    }
    jadwallhorof[o] = '\0';
    return (jadwallhorof);
}

char *ft_strjoin(char *s1, char *s2)
{
    int len1;
    int len2;
    char *fill;
    int i;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    if (!(fill = malloc(sizeof(char) * (len1 + len2 + 1))))
        return (NULL);
    i = 0;
    while (*s1)
        fill[i++] = *s1++;
    while (*s2)
        fill[i++] = *s2++;
    fill[i] = '\0';
    return (fill);
}

char *my_strcut(char *content, int end)
{
    int len;
    int i;
    char *tmp;

    len = ft_strlen(content);
    if (len > end)
        len = end;
    if (!(tmp = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    while (*content && len--)
        tmp[i++] = *content++;
    tmp[i] = '\0';
    return (tmp);
}

int fill_line(char **content, char **line)
{
    int end;
    char *str;

    end = 0;
    while ((*content)[end] != '\n' && (*content)[end] != '\0')
        end++;
    if ((*content)[end] == '\n')
    {
        *line = my_strcut(*content, end);
        str = ft_strdup(*content + end + 1);
        free(*content);
        *content = str;
        return (1);
    }
    else if ((*content)[end] == '\0')
    {
        *line = ft_strdup(*content);
        free(*content);
    }
    return (0);
}

int get_next_line(char **line)
{
    static char *content;
    char *buff;
    char *str;
    int r;

    if (content == NULL)
        content = ft_strdup("");
    if (!(buff = malloc(sizeof(char) * 101)))
        return 0;
    if (!(is_n(content)))
        while ((r = read(0, buff, 100)) > 0)
        {
            buff[r] = '\0';
            str = ft_strjoin(content, buff);
            free(content);
            content = str;
            if (is_n(buff))
                break;
        }
    free(buff);
    return (fill_line(&content, line));
}

int main()
{
    int i;
    char *line = NULL;

    while ((i = get_next_line(&line)) > 0)
    {
        printf("%s\n", line);
        free(line);
        line = NULL;
    }
    printf("%s", line);
    free(line);
    line = NULL;

}