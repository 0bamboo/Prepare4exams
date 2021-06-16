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

int ft_free(FILE *file, char *draw, char *msg)
{
    fclose(file);
    if (draw)
    {
        free(draw);
        draw = NULL;
    }
    if (msg)
        ft_putstr(msg);
    return 1;
}

char *get_zone(FILE *file, t_zone *zone)
{
    int i;
    int ret;
    char *draw;

    if ((ret = fscanf(file, " %f %f %c\n", &zone->width, &zone->height, &zone->ch)) != 3)
        return NULL;
    if (ret == -1)
        return NULL;
    if (zone->width <= 0 || zone->width > 300)
        return NULL;
    if (zone->height <= 0 || zone->height > 300)
        return NULL;
    if (!(draw = malloc(sizeof(char) * zone->height * zone->width)))
        return NULL;
    i = 0;
    while (i < zone->height * zone->width)
        draw[i++] = zone->ch;
    return draw;
}



int main(int ac, char **av)
{
    int i;
    FILE *file;
    t_zone zone;
    char *draw;

    if (ac != 2)
    {
        ft_putstr("Error: argument\n");
        return 1;
    }
    if (!(file = fopen(av[1], "r")))
    {
        ft_putstr("Error: Operation file corrupted\n");
        return 1;
    }
    if (!(draw = get_zone(file, &zone)))
        return (ft_free(file, NULL, "Error: Operation file corrupted\n"));
    if (!(drawing_shape(file, &zone, draw)))
        return (ft_free(file, NULL, "Error: Operation file corrupted\n"));
    i = 0;
    while (i < zone.height)
    {
        write(1, draw + (i * (int)zone.width), zone.width);
        write(1, "\n", 1);
        i++;
    }
    ft_free(file, draw, NULL);
    return 0;
}