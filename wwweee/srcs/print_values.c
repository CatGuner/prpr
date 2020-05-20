#include "ft_printf.h"

void print_value(t_data* setings)
{
    char*       k;          //сделать нулевым, данные не совпадают с выбранным типом, то ничего не выводится, а у меня крашится.

    if (setings->type.p)
    {
        k = ft_itoa_base(16, (long long)setings->value, &setings->flag);
        add_liks("0x", &k);
    }
    else if (setings->type.c || setings->type.s)
        k = (char*)setings->value;
    else if (setings->type.d)
        k = ft_itoa_base(10, read_hlhhll(setings, (int)setings->value), &setings->flag);
    else if (setings->type.u)       // костыльно работает с 0
        k = ft_unsigned_itoa_base(10, read_unsigned_hlhhll(setings, (unsigned int)setings->value));
    else if (setings->type.o)
        k = ft_unsigned_itoa_base(8, read_unsigned_hlhhll(setings, (unsigned int)setings->value));
    else if (setings->type.x || setings->type.X)
    {
        k = ft_unsigned_itoa_base(16, read_unsigned_hlhhll(setings, (unsigned int)setings->value));
        if (setings->type.X)
            change_x_to_X(&k);
    }
    else if (setings->type.f)
        k = convert_to_float(setings);

    set_precision(setings->precision, &k);
    set_flag(setings, &k);
    set_width(setings->width, &k);
    ft_putstr(k);
    free(k);
}
