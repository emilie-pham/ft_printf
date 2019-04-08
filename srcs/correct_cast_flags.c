/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_cast_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:21:02 by epham             #+#    #+#             */
/*   Updated: 2019/04/08 11:06:56 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		correct_flags(long double ival, t_printf *env)
{
	env->preflen = 0;
	if (env->flags & PLUS)
		env->flags &= ~SPACE;
	if ((env->type != 'f' && env->type != 'F')
		&& env->flags & (MINUS | PREC))
		env->flags &= ~ZERO;
	if (ival < 0 && (env->flags & (PLUS | SPACE)))
		env->flags &= ~(PLUS | SPACE);
	if ((env->flags & HASH) && (env->type == 'x' || env->type == 'X'))
		env->flags |= PREF;
	if (env->flags & PREF)
		env->preflen = 2;
	if ((env->flags & HASH) && (env->type == 'o' || env->type == 'O'))
		env->preflen = 1;
	if ((env->flags & HASH || env->flags & PLUS)
		&& (env->type == 'u'))
	{
		env->flags &= ~PLUS;
		env->flags &= ~HASH;
	}
	return (env->flags);
}

void	correct_modif(t_printf *env, long long *val)
{
	env->flags = correct_flags(*val, env);
	if (env->flags & HH)
		*val = (char)*val;
	else if (env->flags & H)
		*val = (short)*val;
	else if (env->flags & LL)
		*val = (long long)*val;
	else if (env->flags & L)
		*val = (long)*val;
	else if (env->flags & J)
		*val = (long long)*val;
	else if (env->flags & Z)
		*val = (size_t)*val;
	else
		*val = (int)*val;
}

void	correct_fmodif(t_printf *env, long double *val)
{
	env->flags = correct_flags(*val, env);
	if (env->flags & LL)
		*val = (long long)*val;
	if (env->flags & L)
		*val = (long)*val;
	else if (env->flags & BIGL)
		*val = (long double)*val;
	else if (env->flags & J)
		*val = (long long)*val;
	else if (env->flags & Z)
		*val = (size_t)*val;
	else
		*val = (double)*val;
}

void	correct_umodif(t_printf *env, unsigned long long *val)
{
	env->flags = correct_flags(*val, env);
	if (env->type == 'U')
		*val = (unsigned long)*val;
	else if (env->type == 'p')
		*val = (unsigned long long)*val;
	else if (env->flags & HH)
		*val = (unsigned char)*val;
	else if (env->flags & H)
		*val = (unsigned short int)*val;
	else if (env->flags & LL)
		*val = (unsigned long long int)*val;
	else if (env->flags & L)
		*val = (unsigned long int)*val;
	else if (env->flags & J)
		*val = (unsigned long long)*val;
	else if (env->flags & Z)
		*val = (size_t)*val;
	else
		*val = (unsigned int)*val;
}
