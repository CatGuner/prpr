#include "ft_printf.h"

void    set_flag(t_data* setings, char** str)
{
    if (!setings->type.c || !setings->type.p || !setings->type.s)
    {
        if (setings->flag.p && !setings->flag.m)
            add_liks("+", str);
        if (setings->flag.m)
            add_liks("-",str);
        if (setings->flag.space && !setings->flag.m)
            add_liks(" ",str);
    }
    if (setings->type.o && setings->flag.grill && ft_strcmp(*str, "0"))
        add_liks("0", str);
    if ((setings->type.x || setings->type.X) && setings->flag.grill && ft_strcmp(*str, "0"))
        add_liks("0x", str);
}