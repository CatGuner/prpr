#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

typedef struct  s_bool
{
    unsigned char n : 1;
}               t_bool;

typedef union	s_union
{
	int			l;
	double		ll;
	char		*text;
}				t_union;

typedef struct	s_flag
{
	unsigned char space : 1;
	unsigned char m : 1;
	unsigned char p : 1;
	unsigned char zero : 1;
	unsigned char grill : 1;		
}				t_flag;

typedef struct	s_modifier
{
	unsigned char h : 1;
	unsigned char hh : 1;
	unsigned char l : 1;
	unsigned char ll : 1;
	unsigned char L : 1;
}				t_modifier;

typedef struct	s_type
{
	unsigned char c : 1;
	unsigned char p : 1;
	unsigned char s : 1;
	unsigned char d : 1;
	unsigned char u : 1;
	unsigned char o : 1;
	unsigned char x : 1;
	unsigned char X : 1;
	unsigned char f : 1;
}				t_type;

union s_flout_double
{
    double d;
    long double Ld;
}       t_flout_double;

typedef struct	s_data
{
	t_flag		flag;
	int			width;
	int			precision;
	t_modifier	mod;
	t_type		type;
	void*       value;
	union s_flout_double dvalue;

}               t_data;

#endif

void                    init_flag(t_flag* f);
void                    init_mod(t_modifier* s);
void                    init_type(t_type* s);
void                    init_data(t_data* s);
t_flag                  spot_flag (char** c);
int                     ft_atoi_2(char **str);
t_modifier              spot_mod(char **c);
t_type                  spot_type(char **c);
void                    ft_printf(char* format, ...);
void                    print_value(t_data* setings);
char*                   ft_itoa_base(const int base, const long long value, t_flag* flag);
void                    change_x_to_X(char** str);
long long               read_hlhhll(t_data* setings, long long num);
unsigned long long      read_unsigned_hlhhll(t_data* setings, unsigned long long num);
char*                   ft_unsigned_itoa_base(const int base, const unsigned long long value);
void                    set_precision(int pres, char** value);
void                    set_width(int pres, char** value);
void                    add_liks(const char* c, char** str);
void                    set_flag(t_data* setings, char** str);
char*                   convert_to_float(t_data* setings);
void                    work_with_L(char** str, long double num, int *precision);
void                    add_liks_back(char** str, const char* c);