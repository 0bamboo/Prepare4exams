#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_cir
{
    char type;
    float x;
    float y;
    float radius;
    char c;
}t_cir;

typedef struct s_zone
{
    float width;
    float height;
    char c;
}t_zone;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *s)
{
    while (*s)
    {
        ft_putchar(*s);
        s++;
    }
}

int is_in_cir(float x, float y, t_cir *c)
{
    float distance;

    distance = sqrtf(powf(x - c->x, 2.) + powf(y - c->y, 2.));
    if (distance <= c->radius)
    {
        if (c->radius - distance < 1.)
            return 2;
        return 1;
    }
    return 0;
}

int drawing_shape(FILE *file, t_zone *zone, char *draw)
{
    int i;
    int j;
    int ret;
    int ret1;
    t_cir c;

    ret = 0;
    while ((ret = fscanf(file, " %c %f %f %f %c\n", &c.type, &c.x, &c.y, &c.radius, &c.c)) == 5)
    {
        if (c.radius <= 0.00000000 || (c.type != 'c' && c.type != 'C'))
            return 0;
        j = 0;
        while (j < zone->height)
        {
            i = 0;
            while (i < zone->width)
            {
                ret1 = is_in_cir(i, j, &c);
                if ((c.type == 'c' && ret1 == 2) || (c.type == 'C' && ret1))
                    draw[j * (int)zone->width + i] = c.c;
                i++;
            }
            j++;
        }
        return 1;
    }
    if (ret != -1)
        return 0;
    return 1;
}

char *get_zone(FILE *file, t_zone *zone)
{
    int i;
    int ret;
    char *draw;

    if ((ret = fscanf(file, " %f %f %c\n", &zone->width, &zone->height, &zone->c)) != 3)
        return NULL;
    if (zone->width <= 0 || zone->height <= 0 || zone->width > 300 || zone->height > 300)
        return NULL;
    if (!(draw = (char *)malloc(sizeof(char) * zone->width *zone->height)))
        return NULL;
    i = 0;
    while (i < zone->width * zone->height)
        draw[i++] = zone->c;
    return draw;
}

int ft_free(FILE *file, char *draw, char *msg)
{
    fclose(file);
    if (draw)
        free(draw);
    if (msg)
        free(msg);
    return 1;
}

int main(int ac, char **av)
{
    FILE *file;
    char *draw;
    int i;
    t_zone zone;

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