#include "ft_printf.h"

void        set_width(int pres, char** value)
{
    char*       str;
    long long   slen;

    slen = (long long)ft_strlen(*value);
    if (slen < pres && pres > 0)
    {
        while (pres-- > slen)
            add_liks(" ", value);
    }
    else if (slen * -1 > pres && pres < 0)
    {
        while (pres++ < (slen * -1))
            add_liks_back(value, " ");
    }
}
