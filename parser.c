/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:21:02 by epham             #+#    #+#             */
/*   Updated: 2019/03/28 19:14:03 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void printBits(unsigned int num)
{
   const int bit_cnt = sizeof(unsigned int) * 8;
   unsigned int mask = (1 << (bit_cnt - 1));

   do
   {
      printf("%u", (num & mask) != 0?1:0);
      mask >>= 1;
   } while (mask > 0);
}

/* LARGEUR ET PRECISION */
size_t	get_width_prec(char **p)
{
	int i;

	i = 0;
	while (ft_isdigit(**p))
	{
		i = i * 10 + (**p - '0');
		(*p)++;
	}
	return (i);
}

void	get_modif(char **p, t_printf *env)
{
	while (**p && (**p == 'h' || **p == 'l' || **p == 'L' || **p == 'j'
		|| **p == 'z'))
	{
		if (**p == 'h')
		{
			if (env->flags & H)
				env->flags |= HH;
			env->flags |= H;
		}
		if (**p == 'l')
		{
			if (env->flags & L)
				env->flags |= LL;
			env->flags |= L;
		}
		if (**p == 'L')
			env->flags |= BIGL;
		(*p)++;
	}
}

int 	correct_flags_int(int ival, t_printf *env)
{
	env->preflen = 0;
	if (env->flags & PLUS)		/* if PLUS, turn of SPACE */
		env->flags &= ~SPACE;
	if (env->flags & (MINUS | PREC))
		env->flags &= ~ZERO;
	if (ival < 0 && (env->flags & (PLUS | SPACE)))
		env->flags &= ~(PLUS | SPACE);
	if ((env->flags & HASH) && (env->type == 'x' || env->type == 'X'))
	{
		env->flags |= PREF;
		env->preflen = 2;
	}
	if ((env->flags & HASH) && (env->type == 'o'))
		env->preflen = 1;
	return (env->flags);
}

void	correct_modif(t_printf *env, intmax_t *val)
{
	env->flags = correct_flags_int(*val, env);
	if (env->flags & HH)
		*val = (char)*val;
	else if (env->flags & H)
		*val = (short)*val;
	else if (env->flags & L)
		*val = (long)*val;
	else if (env->flags & LL)
		*val = (long long)*val;
	else if (env->flags & J)
		*val = (intmax_t)*val;
	else if (env->flags & Z)
		*val = (size_t)*val;
	else
		*val = (int)*val;
}

void	correct_umodif(t_printf *env, uintmax_t *val)
{
	env->flags = correct_flags_int(*val, env);
	if (env->flags & HH)
		*val = (unsigned char)*val;
	else if (env->flags & H)
		*val = (unsigned short int)*val;
	else if (env->flags & L)
		*val = (unsigned long int)*val;
	else if (env->flags & LL)
		*val = (unsigned long long int)*val;
	else if (env->flags & J)
		*val = (uintmax_t)*val;
	else if (env->flags & Z)
		*val = (ssize_t)*val;
	else
		*val = (unsigned int)*val;
}
