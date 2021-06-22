#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_rect
{
    char type;
    float x;
    float y;
    float w;
    float h;
    char c;
}t_rect;

<<<<<<< HEAD
typedef struct s_zone
{
    float width;
    float height;
    char ch;
}t_zone;


=======
>>>>>>> c8270996ebdff4bd4a0eebfe4afd11afddee6aed
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while (str)
    {
        ft_putchar(*str);
        str++;
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

int is_in_rect(float x, float y, t_rect *rect)
{
    if (x < rect->x || y < rect->y || rect->y + rect->h < y || rect->x + rect->w < x)
        return 0;
<<<<<<< HEAD
    if ((x - rect->x < 1.00000000 || rect->x + rect->w - x < 1.00000000) || (y - rect->y < 1.00000000 || rect->y + rect->h - y < 1.00000000))
=======
    if ((x - rect->x < 1.00000000) || (rect->x + rect->w - x < 1.00000000) || (rect->y + rect->h - y < 1.00000000) || y - rect->y < 1.00000000)
>>>>>>> c8270996ebdff4bd4a0eebfe4afd11afddee6aed
        return 2;
    return 1;
}

int drawing_shape(FILE *file, t_zone *zone, char *draw)
{
    int i;
    int j;
    int ret;
<<<<<<< HEAD
    int ret1;
=======
    int r1;
    int i;
    int j;
>>>>>>> c8270996ebdff4bd4a0eebfe4afd11afddee6aed
    t_rect rect;

    ret = 0;
    while ((ret = fscanf(file, " %c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.w, &rect.h, &rect.c)) == 6)
    {
        if (rect.w <= 0.00000000 || rect.h <= 0.00000000 || (rect.type != 'r' && rect.type != 'R'))
            return 0;
        j = 0;
        while(j < zone->height)
        {
            i = 0;
            while (i < zone->width)
            {
<<<<<<< HEAD
                ret1 = is_in_rect(i, j, &rect);
                if ((rect.type == 'r' && ret1 == 2) || (rect.type == 'R' && ret1))
                    draw[j *(int)zone->width + i] = rect.c;
=======
                r1 = is_in_rect(i, j, &rect);
                if ((r1 == 2 && rect.type == 'r') || (rect.type == 'R' && r1))
                    draw[j * (int)zone->width + i] = rect.c;
>>>>>>> c8270996ebdff4bd4a0eebfe4afd11afddee6aed
                i++;
            }
            j++;
        }
        return 1;
    }
    if (ret != 6)
        return 0;
    return 1;
}

char *get_zone(FILE *file, t_zone *zone)
{
<<<<<<< HEAD
    int i;
    int ret;
    char *draw;
=======
    char *draw;
    int ret;
    int i;
>>>>>>> c8270996ebdff4bd4a0eebfe4afd11afddee6aed

    if ((ret = fscanf(file, " %f %f %c\n", &zone->width, &zone->height, &zone->ch) != 3))
        return NULL;
    if (ret == -1)
        return NULL;
    if (zone->width <= 0 || zone->height <= 0 || zone->width > 300 || zone->height > 300)
        return NULL;
<<<<<<< HEAD
    if (!(draw = malloc(sizeof(char) * zone->width *zone->height)))
=======
    if (!(draw = (char *)malloc(sizeof(char)* zone->width *zone->height)))
>>>>>>> c8270996ebdff4bd4a0eebfe4afd11afddee6aed
        return NULL;
    i = 0;
    while (i < zone->width *zone->height)
        draw[i++] = zone->ch;
    return draw;
}

int main(int ac, char **av)
{
    int i;
    FILE *file;
    char *draw;
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