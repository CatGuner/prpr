#include "ft_printf.h"

//изменить название файла

char*   convert_to_float(t_data* setings)
{
    char*       str;
    long long   whole_part;
    char*       w_p;
    int         sign;

    str = (char*)ft_memalloc(sizeof(char) * 2);
    if (setings->mod.L)
    {
        whole_part = (long long)setings->dvalue.Ld;
        w_p = ft_itoa_base(10, whole_part, &setings->flag); // это срочная whole_part
        (whole_part < 0) ? (sign = -1) : (sign = 1);
        work_with_L(&str, setings->dvalue.Ld - (whole_part * sign), &setings->precision);
        add_liks(w_p, &str);
    }
    else
    {
        whole_part = (long long)setings->dvalue.d;
        w_p = ft_itoa_base(10, whole_part, &setings->flag);
        (whole_part < 0) ? (sign = -1) : (sign = 1);
        work_with_L(&str, setings->dvalue.d - (whole_part * sign), &setings->precision);    //опасное неявное преобразование
        add_liks(w_p, &str);
    }
    free(w_p);
    return str;
}

void    work_with_L(char** str, long double num, int *precision)  // надо сделать нормальное округление, потому что его нет
{
    char* fractional_part;
    int     subnum;

    add_liks(".", str);
    // фигово работает с 0
    fractional_part = NULL;
    subnum = 0;
    while (*precision != 0)
    {
        num *= 10;
        subnum = (int)num;
        if (*precision == 1 && (num - subnum >= 0.5))
            num += 1;
        fractional_part = ft_itoa_base(10, (long)num, NULL);
        add_liks_back(str, fractional_part);
        if (*precision < 0)
            (*precision)++;
        else
            (*precision)--;
        num -= (long long)num;
    }
    free(fractional_part);
}
