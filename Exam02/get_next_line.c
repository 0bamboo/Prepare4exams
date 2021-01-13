/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:43:34 by zdnaya            #+#    #+#             */
/*   Updated: 2020/12/26 17:04:33 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char *ft_strdup(char *str)
{
  char *tmp;
  int len;
  
  int i = 0;
  len = ft_strlen(str) + 1;
  if (!(tmp = malloc(len)))
    return (NULL);
  while (str[i] != '\0') {
    tmp[i] = str[i];
    i++;
  }
  tmp[i] = '\0';
  return (tmp);
}

char *ft_strjoin(char *s1, char *s2)
{
  char *tmp;
  int len;
  int i = 0;
  int j = 0;

  len = ft_strlen(s1) + ft_strlen(s2) + 1;
  if (!(tmp = malloc(len)))
    return (NULL);
  tmp[len--] = '\0';
  while (s1[i] != '\0') {
    tmp[j] = s1[i];
    i++;
    j++;
  }
  i = 0;
  while (s2[i] != '\0') {
    tmp[j] = s2[i];
    i++;
    j++;
  }
  return (tmp);
}

int is_newline(char *str)
{
  int i;
  
  i = 0;
  while (str[i] != '\0') {
    if (str[i] == '\n')
      return (1);
    i++;
  }
  return (0);
}

char *my_strcut(char *s, int n)
{
  int len;
  char *tmp;
  int i = 0;

  len = ft_strlen(s);
  if (len > n)
    len = n;
  if (!(tmp = malloc(len + 1)))
    return (NULL);
  while (*s && len--)
    tmp[i++] = *(s++);
  tmp[i] = '\0';
  return (tmp);
}

int fill_line(char **content, char **line)
{
  int end;
  char *tmp;
  
  end = 0;
  while ((*content)[end] != '\n' && (*content)[end] != '\0')
    end++;
  if ((*content)[end] == '\n') {
    *line = my_strcut(*content, end);
    tmp = ft_strdup(*content + end + 1);
    free(*content);
    *content = tmp;
    return (1);
  } 
  else if ((*content[end]) == '\0')
  {
    *line = ft_strdup(*content);
    free(*content);
  }
  return (0);
}

int get_next_line(char **line)
{
  int r;
  static char *content;
  char *tmp;
  char *buff;
  
  if (content == NULL)
    content = ft_strdup("");
  buff = malloc(sizeof(char) * 101);
  if (!(is_newline(content)))
    while ((r = read(0, buff, 100)) > 0)
    {
      buff[r] = '\0';
      tmp = ft_strjoin(content, buff);
      free(content);
      content = tmp;
      if (is_newline(buff))
        break;
    }
  free(buff);
  return (fill_line(&content, line));
}

int main(void) {
  int r;
  char *line;

  line = NULL;
  while ((r = get_next_line(&line)) > 0) {
    printf("%s\n", line);
    free(line);
    line = NULL;
  }
  printf("%s", line);
  free(line);
  line = NULL;
}
