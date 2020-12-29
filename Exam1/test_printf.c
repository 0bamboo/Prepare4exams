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
    fs->width = 0;
    fs->len = 0;
    fs->precision = 0;
    fs->point = 0;
    fs->out = "hel";
}

void gather_flag(t_flg *fs, char *s, va_list *ap)
{
    while (*s)
    {
        if (*s == 'd' || *s == 's' || *s == 'x')
        {
            fs->sp_c = *s;
            if (*s == 'd')
                fs->d = va_arg(*ap, int);
            else if (*s == 's')
                fs->s = va_arg(*ap, char *);
            else if (*s == 'x')
                fs->u = va_arg(*ap, unsigned int);
            ++s;
            break;
        }
        if (*s == '.')
        {
            fs->point = 1;
            fs->precision = ft_atoi(++s);
            while (is_dig(*s))
                s++;
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
    int l;

    l = 1;
    while (n / 10)
    {
        n /= 10;
        l++;
    }
    return (l);
}

void ft_putnbr(long l, t_flg *fs)
{
    if (l > 9)
        ft_putnbr((l / 10), fs);
    ft_putchar((l % 10) + '0', 1,fs);
}

void parse_dec(t_flg *fs)
{
    fs->len = nbrlen(fs->d);
    if (fs->d < 0)
        fs->sign = 1;
    fs->l = fs->sign ? - (long)fs->d : (long)fs->d;
    if (!fs->l && fs->point && fs->precision == 0)
        fs->len = 0;
    fs->precision -= (fs->precision > fs->len) ? fs->precision : fs->len;
    fs->width -= (fs->width > fs->precision + fs->sign + fs->len) ? fs->precision + fs->sign + fs->len : fs->width;
}

void print_dec(t_flg *fs)
{
    fs->width ? ft_putchar(' ', fs->width, fs) : 0;
    fs->sign ? ft_putchar('-', 1, fs) : 0;
    fs->precision ? ft_putchar('0', fs->precision, fs) : 0;
    if (fs->len)
        ft_putnbr(fs->l, fs);
}

void global_print(t_flg *fs)
{
    if (fs->sp_c == 'd')
    {
        parse_dec(fs);
        print_dec(fs);
    }
    else if (fs->sp_c == 's')
    {
        parse_str(fs);
        print_str(fs);
    }
    else if (fs->sp_c == 'x')
    {
        parse_hex(fs);
        print_hex(fs);
    }
}

int ft_printf(const char *s, ...)
{
    va_list ap;
    t_flg fs;

    fs.ret = 0;
    va_start(ap, s);
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