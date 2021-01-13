/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:41:09 by abdait-m          #+#    #+#             */
/*   Updated: 2020/12/15 16:56:23 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int get_next_line(char **line);
int ft_strlen(char *str);
char *ft_strdup(char *str);
char *ft_strjoin(char *st1, char *st2);
char *my_strcut(char *str, int n);
int fill_line(char **content, char **line);
int is_n(char *st);

#endif