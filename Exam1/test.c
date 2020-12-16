/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:44:59 by abdait-m          #+#    #+#             */
/*   Updated: 2020/12/15 20:54:56 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int  ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
        
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

char *ft_strjoin(char *st1, char *st2)
{
    int len1;
    int len2;
    int i;
    char *fill;

    len1 = ft_strlen(st1);
    len2 = ft_strlen(st2);
    fill = malloc(sizeof(char) * (len1 + len2 + 1));
    while (*st1)
        fill[i++] = *st1++;
    while (*st1)
        fill[i++] = *st2++;
    fill[i] = '\0';
    return (fill);
}

char *ft_strdup(char *st)
{
    int i;
    char *buff;
    int len;

    len = ft_strlen(st) + 1;
    buff = malloc(sizeof(char) * len);
    i = 0;
    while (st[i])
    {
        buff[i] = st[i];
        i++;
    }
    buff[i] = '\0';
    return (buff);
}

char  *my_strcut(char *str, int end)
{
    int i;
    int len;
    char *tmp;

    len = ft_strlen(str);
    if (len > end)
        len = end;
    tmp = malloc(sizeof(char) * (len + 1));
    i = 0;
    while (*str && len--)
        tmp[i++] = *str++;
    tmp[i] = '\0';
    return (tmp);
}

int     fill_line(char **content, char **line)
{
    int end;
    char *tmp;

    end = 0;
    while ((*content)[end] != '\n' && (*content)[end] != '\0')
        end++;
    if ((*content)[end] == '\n')
    {
        *line = my_strcut(*content, end);
        tmp = ft_strdup(*content);
        free(*content);
        *content = tmp;
        return (1);
    }
    else if ((*content)[end] == '\0')
    {
        *line = ft_strdup(*content);
        free(*content);
    }
    return (0);
}

int  get_next_line(char **line)
{
    static char *content;
    char *buff;
    char *tmp;
    int r;

    if (content == NULL)
        content = ft_strdup("");
    buff = malloc(sizeof(char) * 101);
    if (!(is_n(content)))
        while ((r = read(0, buff, 100)) > 0)
        {
            buff[r] = '\0';
            tmp = ft_strjoin(content, buff);
            free(content);
            content = tmp;
            if (is_n(buff))
                break;
        }
    free(buff);
    return (fill_line(&content, line));
}