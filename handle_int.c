/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:52:50 by epham             #+#    #+#             */
/*   Updated: 2019/03/28 20:32:47 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* FUNCTION THAT GETS SIZE OF STRING NEEDED */
void	sz(intmax_t nb, t_printf *env, size_t width, size_t len)
{
	size_t flags;

	flags = env->flags;
	env->sz = (width > env->prec) ? width : env->prec;
	env->sz = (len > env->sz) ? len : env->sz;
	if (env->sz == len && ((nb >= 0 && (flags & (PLUS | SPACE)) && env->prec == 0)
		|| (env->prec > 0 && env->prec < env->sz && (env->flags & SPACE))))
		env->sz = len + 1;
	if ((nb < 0 && (env->prec + 1) > env->sz) 
		|| (nb >= 0 && (flags & (PLUS | SPACE)) && (env->prec + 1) > env->sz))
		env->sz = env->prec + 1;
	if (env->prec > 0 && env->prec > env->sz)
		env->sz = env->prec;
}

/* FUNCTION THAT GETS NUMBER OF ZEROS AND SPACES TO PRINT */
void	get_space_zero(intmax_t ival, t_printf *env, size_t width, size_t prec)
{
	size_t len;

	len = env->len;
	env->space = 0;
	env->zero = 0;
	if ((width > prec) && (prec >= len))
	{
		env->space = width - prec;
		env->zero = prec - len;
		if (ival < 0 || (ival > 0 && env->flags & PLUS))
			env->space = width - prec - 1;
		if (ival < 0)
			env->zero = prec - len + 1;
	}
	if ((width > len) && (len >= prec))
	{
		env->zero = (env->flags & ZERO) ? width - len : 0;
		env->space = (env->flags & ZERO) ? 0 : width - len;
		if ((env->flags & PLUS) && ival > 0)
		{
			env->zero = (env->flags & ZERO) ? width - len - 1: 0;
			env->space = (env->flags & ZERO) ? 0 : width - len - 1;		/* if zeros then no space */
		}
		if (ival > 0 && env->space && (env->flags & SPACE))	/* remove space  */
				env->space -= 1;
		if (ival > 0 && (env->flags & SPACE) && env->zero)
				env->zero -= 1;
	}
	if (((prec > width) && (width > len)) || ((prec > width) && (prec > len)))
	{
		env->zero = prec - len;
		if (ival < 0)
			env->zero += 1;
	}
	/* if nb > 0 and SIZE = nblen */
	if (ival >= 0 && (env->flags & SPACE) && (env->sz == env->len + 1))
		env->space = 1;
}

char *right(char *nb, t_printf *env, char *print)
{
	int i;

	i = 0;
	if ((env->flags & SPACE) && (env->sz != env->len + 1))
		env->space++;
	while ((env->space)--)
		print[i++] = ' ';
	if (nb[0] == '-')
	{
		nb++;
		print[i++] = '-';
	}
	else if (env->flags & PLUS)
		print[i++] = '+';
	while ((env->zero)--)
		print[i++] = '0';
	if (!(env->flags & NULPREC))
	{
		while (*nb)
			print[i++] = *nb++;
	}
	return (print);
}

char *left(char *nb, t_printf *env, char *print)
{
	int i;

	i = 0;
	if (nb[0] == '-')
	{
		nb++;
		print[i++] = '-';
	}
	else if (env->flags & PLUS)
		print[i++] = '+';
	else if (env->flags & SPACE)
		print[i++] = ' ';
	while ((env->zero)--)
		print[i++] = '0';
	if (!(env->flags & NULPREC))
	{
		while (*nb)
			print[i++] = *nb++;
	}
	while ((env->space)--)
		print[i++] = ' ';
	return (print);
}

int	ft_printnb(intmax_t ival, t_printf *env)
{
	char		*print;
	char		*nb;
	size_t		i;
	size_t 		len;

	nb = ft_itoa_base(ival, 10);
	env->len = ft_strlen(nb);
	sz(ival, env, env->width, env->len);
	// printf("size = %zu\n", env->sz);
	print = ft_strnew(env->sz);
	get_space_zero(ival, env, env->width, env->prec);
	i = (env->flags & MINUS) ? 0 : env->sz - 1;
	if (i == 0)
		print = left(nb, env, print);
	else if (i == env->sz - 1)
		print = right(nb, env, print);
	ft_putstr(print);
	len = ft_strlen(print);
	free(print);
	free(nb);
	return (len);
}
