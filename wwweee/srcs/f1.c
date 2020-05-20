#include "ft_printf.h"

t_flag  spot_flag (char** c)
{
    t_flag  flag;
    init_flag(&flag);
    if (**c == '#')
        flag.grill = 1;
    else if (**c == '0')
        flag.zero = 1;
//    else if (**c == '-')
//        flag.m = 1;
    else if (**c == '+')
        flag.p = 1;
    else if (**c == ' ')
        flag.space = 1;
    if (**c == '#' || **c == '0' /* || **c == '-'*/ || **c == '+' || **c == ' ')
        (*c)++;
    return (flag);
}

int		ft_atoi_2(char **ptr)
{
    int					sign;
    unsigned long long	num;
    unsigned long long	maxlong;
    unsigned long long	minlong;

    minlong = 9223372036854775808ULL;
    maxlong = 9223372036854775807ULL;
    num = 0;
    sign = 1;
    while (*(*ptr) == ' ' || (*(*ptr) >= '\t' && *(*ptr) <= '\r'))
        (*ptr)++;
    if (**ptr == '-')
    {
        sign = -1;
        (*ptr)++;
    }
    else if (**ptr == '+')
        (*ptr)++;
    while (**ptr >= '0' && **ptr <= '9' && **ptr)
        num = num * 10 + (*(*ptr)++ - '0') * sign;
    if (num < minlong && sign == -1)
        return (0);
    if (num > maxlong && sign == 1)
        return (-1);
    return (num);
}

t_modifier spot_mod(char **c)
{
    t_modifier mod;
    init_mod(&mod);
    if (**c == 'h' && *(*c + 1) == 'h')
        mod.hh = 1;
    else if (**c == 'h')
        mod.h = 1;
    else if (**c == 'l' && *(*c + 1) == 'l')
        mod.ll = 1;
    else if (**c == 'l')
        mod.l = 1;
    else if (**c == 'L')
        mod.L = 1;
    if (mod.hh || mod.ll)
        *c += 2;
    else if (mod.L || mod.l || mod.h)
        (*c)++;
    return (mod);
}

t_type  spot_type(char **c)
{
    t_type t;
    init_type(&t);
    if (**c == 'c')
        t.c = 1;
    else if (**c == 'p')
        t.p = 1;
    else if (**c == 's')
        t.s = 1;
    else if (**c == 'd' || **c == 'i')
        t.d = 1;
    else if (**c == 'u')
        t.u = 1;
    else if (**c == 'o')
        t.o = 1;
    else if (**c == 'x')
        t.x = 1;
    else if (**c == 'X')
        t.X = 1;
    else if (**c == 'f')
        t.f = 1;
//    if (t.c || t.p || t.s || t.d || t.u || t.o || t.x || t.X)
//        (*c)++;
    return (t);
}
