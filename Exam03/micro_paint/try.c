#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_zone
{
    float width;
    float height;
    char ch;
}t_zone;

typedef struct s_rect
{
    char type;
    float x;
    float y;
    float w;
    float h;
    char c;
}t_rect;

typedef struct s_rect
{
    char type;
    float x;
    float   y;
    float w;
    float h;
    char c;
}t_rect;

void _ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_puts(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}

