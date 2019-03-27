/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:21:02 by epham             #+#    #+#             */
/*   Updated: 2019/03/26 17:18:35 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

void	get_modif(char **p, int flags)
{
	while (**p && (**p == 'h' || **p == 'l' || **p == 'L'))
	{
		if (**p == 'h')
		{
			if (flags & H)
				flags |= HH;
			flags |= H;
		}
		if (**p == 'l')
		{
			if (flags & L)
				flags |= LL;
			flags |= L;
		}
		if (**p == 'L')
			flags |= BIGL;
		(*p)++;
	}
}

int 	correct_flags_int(int ival, int flags)
{
	// printf("before correct : \n");
	// printBits(flags);

	if (flags & PLUS)		/* if PLUS, turn of SPACE */
		flags &= ~SPACE;
	if (flags & (MINUS | PRECISION))
		flags &= ~ZERO;
	if (ival < 0 && (flags & (PLUS | SPACE)))
		flags &= ~(PLUS | SPACE);				/*  */
	// printf("after correct : \n");
	// printBits(flags);
	return (flags);
}

void	correct_modif(t_printf *env, intmax_t *val)
{
	env->flags = correct_flags_int(*val, env->flags);
	if (env->flags & HH)
		*val = (char)*val;
	if (env->flags & H)
		*val = (short int)*val;
	if (env->flags & L)
		*val = (long int)*val;
	if (env->flags & LL)
		*val = (long long int)*val;
	if (env->flags & BIGL)
		*val = (long double)*val;
}

void	correct_umodif(t_printf *env, uintmax_t *val)
{
	env->flags = correct_flags_int(*val, env->flags);
	if (env->flags & HH)
		*val = (char)*val;
	if (env->flags & H)
		*val = (short int)*val;
	if (env->flags & L)
		*val = (long int)*val;
	if (env->flags & LL)
		*val = (long long int)*val;
	if (env->flags & BIGL)
		*val = (long double)*val;
}
