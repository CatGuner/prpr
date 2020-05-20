#include "ft_printf.h"

long long    read_hlhhll(t_data* setings, long long num)
{
    if (setings->mod.h)
        return ((short int)setings->value);
    else if (setings->mod.hh)
        return ((char)setings->value);
    else if (setings->mod.l)
        return ((long int)setings->value);
    else if (setings->mod.ll)
        return ((long long int)setings->value);
    return (num);
}

unsigned long long    read_unsigned_hlhhll(t_data* setings, unsigned long long num)
{
    if (setings->mod.h)
        return ((unsigned short int)setings->value);
    else if (setings->mod.hh)
        return ((unsigned char)setings->value);
    else if (setings->mod.l)
        return ((unsigned long int)setings->value);
    else if (setings->mod.ll)
        return ((unsigned long long int)setings->value);
    return (num);

}
