#include "ft_printf.h"

char	*join_let(char s1, char *s2)
{
    char	*str;
    char	cs1;
    char	*cs2;
    size_t	i;
    size_t  o;

    i = 0;
    o = 0;
    cs1 = (char)s1;
    cs2 = (char*)s2;
    if (!s1 || !s2)
        return (0);
    if ((str = (char*)ft_memalloc(ft_strlen(cs2) + 2)))
    {
        str[i++] = cs1;
        while (cs2[o] != '\0')
            str[i++] = cs2[o++];
        return (str);
    }
    return (0);
}

char*   ft_itoa_base(const int base, const long long value)
{
    long long   determ;
    char        *str;
    char        newchar;
    int         sign;
    char        *ptr;

    sign = 1;
    if (value < 0)
        sign = -1;
    determ = value;
    newchar = 0;
    str = (char*)ft_memalloc(sizeof(char) + 2);
    while (determ)
    {
        int num = determ % base * sign;
        if (num > 9 && num < 16)
            newchar = num + 87;
        else
            newchar = num + '0';
        ptr = str;
        str = join_let(newchar, ptr);
        free(ptr);
        ptr = NULL;
        determ /= base;
    }
    if (sign == -1)
    {
        ptr = str;
        str = join_let('-', ptr);
        free(ptr);
        ptr = NULL;
    }
    if (value == 0)
    {
        ptr = str;
        str = join_let('0', ptr);
        free(ptr);
        ptr = NULL;
    }
    return (str);
}

char*   ft_unsigned_itoa_base(const int base, const unsigned long long value)
{
    unsigned long long   determ;
    char        *str;
    char        newchar;
    char        *ptr;

    determ = value;
    newchar = 0;
    str = (char*)ft_memalloc(sizeof(char) + 2);
    while (determ)
    {
        int num = determ % base;
        if (num > 9 && num < 16)
            newchar = num + 87;
        else
            newchar = num + '0';
        ptr = str;
        str = join_let(newchar, ptr);
        free(ptr);
        ptr = NULL;
        determ /= base;
    }
    if (value == 0)
    {
        ptr = str;
        str = join_let('0', ptr);
        free(ptr);
        ptr = NULL;
    }
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