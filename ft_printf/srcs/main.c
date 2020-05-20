#include "ft_printf.h"
 
void ft_printf(char* format, ...)
{
    t_data  setings;
    va_list factor;         // указатель на необязательный параметр
    va_start(factor, format);   // устанавливаем указатель
    char *c = format;           // исправить
    while (*c)
    {
        init_data(&setings);
        if(*c != '%')
            ft_putchar(*c);
        else
        {
            c++;
            if (*c == '%')
            {
                ft_putchar(*c);
                break;
            }
            setings.flag = spot_flag(&c);
            if (ft_isdigit(*c))
                setings.width = ft_atoi_2(&c);
            if (*c == '.')
            {
                c++;
                setings.precision = ft_atoi_2(&c);
            }
            setings.mod = spot_mod(&c);
            setings.type = spot_type(&c);
            setings.value = va_arg(factor, void*);
            print_value(&setings);
        }
        c++;
    }
    va_end(factor);
}
 
int main(void)
{
    char* a;
    int b = 123456;
    int d1=123, d2=42, d3=1543;
    ft_printf ("%-d\n%-d\n%-d\n",d1,d2,d3);
    printf ("%-d\n%-d\n%-d\n",d1,d2,d3);
    return 0;
}
