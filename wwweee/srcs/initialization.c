#include "ft_printf.h"

void	init_flag(t_flag* f)
{
	f->space = 0;
	f->m = 0;
	f->p = 0;
	f->zero = 0;
	f->grill = 0;
}

void	init_mod(t_modifier* s)
{
	s->h = 0;
	s->hh = 0;
	s->l = 0;
	s->ll = 0;
	s->L = 0;
}

void	init_type(t_type* s)
{
	s->c = 0;
	s->p = 0;
	s->s = 0;
	s->d = 0;
	s->u = 0;
	s->o = 0;
	s->x = 0;
	s->X = 0;
	s->f = 0;
}

void	init_data(t_data* s)
{
	init_flag(&s->flag);
	s->width = 0;
	s->precision = 0;
	init_mod(&s->mod);
	init_type(&s->type);
	s->dvalue.d = 0;
	s->dvalue.Ld = 0;
}
