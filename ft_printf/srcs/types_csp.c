#include "ft_printf.h"

char    type_c(t_data* setings)
{
    return ((char)setings->value);
}

char*   type_s(t_data* setings)
{
    return ((char*)setings->value);
}

void*   type_p(t_data* setings)
{
    return ((void*)setings->value);
}