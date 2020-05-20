#include "ft_printf.h"

void       set_precision(int pres, char** value)
{
    char*       str;
    long long   slen;

    slen = (long long)ft_strlen(*value);
    if (slen < pres && pres > 0)
    {
        while (pres > slen)
        {
            str = *value;
            *value = join_let('0', str);
            pres--;
        }
    }
    else if (slen * -1 > pres && pres < 0)
    {
        while (pres < (slen * -1))
        {
            str = *value;
            *value = ft_strjoin(str, " ");
            pres++;
        }
    }
    free (str);
}