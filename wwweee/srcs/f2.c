#include "ft_printf.h"

void    add_liks(const char* c, char** str)
{
    char        *ptr;

    ptr = *str;
    *str = ft_strjoin(c, ptr);
    free(ptr);
    ptr = NULL;
}

void    add_liks_back(char** str, const char* c)
{
    char    *ptr;

    ptr = *str;
    *str = ft_strjoin(ptr, c);
    free(ptr);
    ptr = NULL;
}
char*   ft_itoa_base(const int base, const long long value, t_flag* flag)
{
    long long   determ;
    char        *str;
    char        *newchar;
    int         sign;

    sign = 1;
    if (value < 0)
        sign = -1;
    determ = value;
    str = (char*)ft_memalloc(sizeof(char) * 2);
    newchar = (char*)ft_memalloc(sizeof(char) * 2);
    while (determ)
    {
        newchar[0] = determ % base * sign +
                     (determ % base * sign > 9 && determ % base * sign < 16 ? 87 : '0');
        add_liks(newchar, &str);
        determ /= base;
    }
    if (sign == -1)
        flag->m = 1;
    if (value == 0)
        add_liks("0", &str);
    free(newchar);
    return (str);
}

char*   ft_unsigned_itoa_base(const int base, const unsigned long long value)
{
    unsigned long long   determ;
    char        *str;
    char        *newchar;

    determ = value;
    str = (char*)ft_memalloc(sizeof(char) + 2);
    newchar = (char*)ft_memalloc(sizeof(char) * 2);
    while (determ)
    {
        newchar[0] = determ % base *  +
                     (determ % base  > 9 && determ % base < 16 ? 87 : '0');
        add_liks(newchar, &str);
        determ /= base;
    }
    if (value == 0)
        add_liks("0", &str);
    free(newchar);
    return (str);
}

void    change_x_to_X(char** str)
{
    char *ptr;

    ptr = *str;
    while (*ptr)
    {
        if (*ptr > 96 && *ptr < 103)
            *ptr -= 32;
        ptr++;
    }
}