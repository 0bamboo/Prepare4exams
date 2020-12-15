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
        tmp = ft_strdup(*content + end + 1);
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


int get_next_line(char **line)
{
    static char *content;
    char *buff;
    char *tmp;
    int r;

    if (content == NULL)
        content = ft_strdup("");
    buff = malloc(sizeof(char) * 101);
    if (!(is_n(content)))
        while ((r = read(0, buff, 100)))
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