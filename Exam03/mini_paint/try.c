#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_circle
{
    char type;
    float x;
    float y;
    float radius;
    char c;
}t_circle;

typedef struct s_zone
{
    float width;
    float height;
    char ch;
}t_zone;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    while (*s)
    {
        ft_putchar(*s);
        s++;
    }
}

int ft_free(FILE *file, char *draw, char *msg)
{
    fclose(file);
    if (draw)
        free(draw);
    if (msg)
        ft_putstr(msg);
    return 1;
}

int is_in_circle(float x, float y, t_circle *cir)
{
    float distance;

    distance = sqrtf(powf(x - cir->x, 2.) + powf(y - cir->y, 2.));
    if (distance <= cir->radius)
    {
        if (cir->radius - distance < 1.)
            return 2;
        return 1;
    }
    return 0;
}


int     drawing_shape(FILE *file, t_zone *zone, char *draw)
{
    int ret;
    int ret1;
    int i;
    int j;
    t_circle c;

    ret = 0;
    while ((ret = fscanf(file, " %c %f %f %f %c\n", &c.type, &c.x, &c.y, &c.radius, &c.c)) == 5)
    {
        puts("hiiii");
        if (c.radius <= 0.00000000 || (c.type != 'c' && c.type != 'C'))
            return 0;
        j = 0;
        while (j < zone->height)
        {
            i = 0;
            while (i < zone->width)
            {
                ret1 = is_in_circle(i, j, &c);
                if ((ret1 == 2 && c.type == 'c') || (ret1 && c.type == 'C'))
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
    int ret;
    int i;
    char *draw;

    if ((ret = fscanf(file, " %f %f %c\n", &zone->width, &zone->height, &zone->ch)) != 3)
        return 0;
    if (ret == -1)
        return 0;
    if (zone->width <= 0 || zone->height <= 0 || zone->width > 300 || zone->height > 300)
        return 0;
    if (!(draw = malloc(sizeof(char) *zone->width *zone->height)))
        return 0;
    i = 0;
    while (i < zone->width *zone->height)
        draw[i++] = zone->ch;
    return draw;
}

int main(int ac, char **av)
{
    int i;
    char *draw;
    FILE *file;
    t_zone zone;

    if (ac != 2)
    {
        ft_putstr("Error: argument\n");
        return 1;
    }
    puts("hi");
    if (!(file = fopen(av[1], "r")))
    {
        ft_putstr("Error: Operation file corrupted\n");
        return 1;
    }
    puts("hi");
    if (!(draw = get_zone(file, &zone)))
        return (ft_free(file, NULL, "Error: Operation file corrupted\n"));
    puts("hi");
    if (!(drawing_shape(file, &zone, draw)))
        return (ft_free(file, NULL, "Error: Operation file corrupted\n"));
    i = 0;
    while (i < zone.height)
    {
        write(1, draw +(i *(int)zone.width), zone.width);
        write(1, "\n", 1);
        i++;
    }
    ft_free(file, draw, NULL);
    return 0;

}