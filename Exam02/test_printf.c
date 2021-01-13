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

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

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
} t_flg;

void ft_putchar(char c, int n, t_flg *fs);
void ft_puststr(char *s, t_flg *fs);
int is_dig(char c);
int ft_atoi(char *s);
int len(char *s);
void init_flag(t_flg *fs);
void gather_flag(t_flg *fs, char *s, va_list *ap);
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

void ft_putchar(char c, int n, t_flg *fs)
{
    fs->ret += n;
    while (n--)
        write(1, &c, 1);
}

void init_flag(t_flg *fs)
{
    fs->sp_c = 0;
    fs->sign = 0;
    fs->len = 0;
    fs->precision = 0;
    fs->point = 0;
    fs->width = 0;
    fs->out = "fun";
}

int is_dig(char c)
{
    return (c >= '0' && c <= '9');
}

int atoi(char *s)
{
    int i;

    i = 0;
    while (is_dig(*s))
        i = (i * 10) + (*s++ - '0');
    return (i);
}

void gather_flag(t_flg *fs, char *s, va_list *ap)
{
    while (*s)
    {
        if (*s == 'd' || *s == 'x' || *s == 's')
        {
            fs->sp_c = *s;
            if (*s == 'd')
                va_arg(*ap, int);
            else if (*s == 'x')
                va_arg(*ap, char *);
            else if (*s == 's')
                va_arg(*ap, unsigned int);
            ++s;
            break;
        }
        if (*s == '.')
        {
            fs->point = 1;
            fs->precision = ft_atoi(++s);
            while (is_dig(*s))
                ++s;
        }
        if (is_dig(*s))
        {
            fs->width = ft_atoi(s);
            while (is_dig(*s))
                s++;
        }
    }
    fs->out = s;
}

int nbrlen(int n)
{
    int len;

    len = 1;
    while (n / 10)
    {
        n /= 10;
        len++;
    }
    return (len);
}

void ft_putnbr(long l, t_flg *fs)
{
    if (l > 9)
        ft_putnbr((l / 10), fs);
    ft_putchar((l % 10) + '0', 1,fs);
}

int len(char *s)
{
    int len;

    len = 0;
    if (s)
        while (*s++)
            len++;
    return (len);
}

void ft_putstr(char *s, t_flg *fs)
{
    if (fs->sp_c == 's' && s)
        while (fs->len--)
            ft_putchar(*s++, 1, fs);
    else if (s)
        while (*s)
            ft_putchar(*s++, 1,fs);
}

void parse_and_print_str(t_flg *fs)
{
    fs->len = fs->s != NULL ? len(fs->s) : 6;
    fs->len = (fs->point && fs->len > fs->precision) ? fs->precision : fs->len;
    fs->width -= (fs->width > fs->len) ? fs->len : fs->width;
    fs->width ? ft_putchar(' ', fs->width, fs) : 0;
    if (fs->s != NULL)
        ft_putstr(fs->s, fs);
    else if (fs->s == NULL)
        ft_putstr("(null)", fs);
}


void parse_and_print_dec(t_flg *fs)
{
    fs->len = nbrlen(fs->d);
    if (fs->d < 0)
        fs->sign = 1;
    fs->l = fs->sign ? -(long)fs->d : (long)fs->d;
    if (!fs->l && fs->point && fs-> precision == 0)
        fs->len = 0;
    fs->precision -= (fs->precision > fs->len) ? fs->len : fs->precision;
    fs->width -= (fs->width > fs->precision + fs->sign + fs->sign) ? fs->precision + fs->sign + fs->len : fs->width;
    fs->width ? ft_putchar(' ', fs->width, fs) : 0;
    fs->sign ? ft_putchar('-', 1, fs) : 0;
    fs->precision ? ft_putchar('0', fs->precision, fs) : 0;
    if (fs->len)
        ft_putnbr(fs->l, fs);
}

void glabal_print(t_flg *fs)
{
    if (fs->sp_c == 'd')
        parse_and_print_dec(fs);
    else if (fs->sp_c == 's')
        parse_and_print_str(fs);
    else if (fs->sp_c == 'x')
        parse_and_print_hex(fs);
}

int ft_printf(const char *s, ...)
{
    va_list ap;
    t_flg fs;

    va_start(ap, s);
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