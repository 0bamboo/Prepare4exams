/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:03:54 by abdait-m          #+#    #+#             */
/*   Updated: 2020/12/17 19:22:25 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

#define aaaa printf

typedef struct s_f
{
    char sp_c;
    int width;
    int sign;
    int precision;
    int point;
    int len;
    int d;
    unsigned int u;
    long l;
    char *s;
    char *out;
    int ret;
}       t_flg;

void    ft_putchar(char c, int n, t_flg *fs);
void    ft_puststr(char *s, t_flg *fs);
int     is_dig(char c);
int     ft_atoi(char *s);
int     len(char *s);
void    init_flag(t_flg *fs);
void    gather_flag(t_flg *fs, char *s, va_list *ap);
int nbrlen(int n);
void parse_dec(t_flg *fs);
void ft_putnbr(long l, t_flg *fs);
void print_dec(t_flg *fs);
char hex_dig(int n);
char *hex_conv(unsigned int u, int step);
void parse_hex(t_flg *fs);
void parse_str(t_flg *fs);
void print_hex(t_flg *fs);
void print_str(t_flg *fs);
void global_print(t_flg *fs);

int     ft_printf(const char *s, ...)
{
    va_list ap;
    t_flg fs;

    fs.ret = 0;
    while (*s)
    {
        while (*s && *s != '%')
            ft_putchar(*s++, 1, &fs);
        if (*s && *s == '%')
        {
            init_flag(&fs);
            gather_flag(&fs, (char *)++s, &ap);
            global_print(&fs);
            s = fs.out;
        }
    }
    return (fs.ret);
}