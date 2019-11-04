/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:52:50 by epham             #+#    #+#             */
/*   Updated: 2019/04/15 20:19:15 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	size(long long nb, t_printf *env, int width, int len)
{
	int flags;

	flags = env->flags;
	env->sz = (width > env->prec) ? width : env->prec;
	env->sz = (len > env->sz) ? len : env->sz;
	if (env->sz == len && ((nb >= 0 && (flags & (PLUS | SPACE))
		&& len + 1 >= env->prec)
		|| (env->prec > 0 && env->prec < env->sz && (env->flags & SPACE))))
		env->sz = len + 1;
	if ((nb < 0 && (env->prec + 1) > env->sz)
		|| (nb >= 0 && (flags & (PLUS | SPACE)) && (env->prec + 1) > env->sz))
		env->sz = env->prec + 1;
	if (env->prec > 0 && env->prec > env->sz)
		env->sz = env->prec;
}

void	get_space_zero1(long long ival, t_printf *env, int w, int p)
{
	if ((w > p) && (p >= env->len))
	{
		env->space = (ival < 0 || (ival >= 0 && env->flags & (PLUS)))
		? w - p - 1 : w - p;
		env->zero = (ival < 0) ? p - env->len + 1 : p - env->len;
	}
	if ((w > env->len) && (env->len > p))
	{
		env->zero = (env->flags & ZERO) ? w - env->len : 0;
		env->space = (env->flags & ZERO) ? 0 : w - env->len;
		if ((env->flags & PLUS) && ival >= 0)
		{
			env->zero = (env->flags & ZERO) ? w - env->len - 1 : 0;
			env->space = (env->flags & ZERO) ? 0 : w - env->len - 1;
		}
		env->zero -= ival > 0 && (env->flags & SPACE) && env->zero ? 1 : 0;
	}
}

void	get_space_zero2(long long ival, t_printf *env, int w, int p)
{
	if (((p > w) && (w > env->len)) || ((p > w) && (p >= env->len)))
		env->zero = ival < 0 ? p - env->len + 1 : p - env->len;
	if (ival >= 0 && (env->flags & SPACE) && (env->sz == env->len + 1
		|| env->sz == p + 1 || env->sz == w))
	{
		env->space += env->space ? 0 : 1;
		env->zero -= env->zero > 0 && env->space == 1
		&& env->zero == w - env->len ? 1 : 0;
	}
	if (w == p && w > env->len)
	{
		env->zero = ival < 0 ? w - env->len + 1 : w - env->len;
		env->space = env->flags & ZERO ? 0 : env->space;
	}
	if (w == p && w == env->len)
		env->zero = ival < 0 ? 1 : env->zero;
}

char	*fill_int(char *nb, t_printf *env, char *print, int lr)
{
	int i;

	i = 0;
	while (lr == 1 && env->space > 0 && (env->space)--)
		print[i++] = ' ';
	if (env->flags & SPACE && env->space > 0 && (env->space)--)
		print[i++] = ' ';
	else if (env->flags & PLUS && nb[0] != '-')
		print[i++] = '+';
	else if (nb[0] == '-')
	{
		nb++;
		print[i++] = '-';
	}
	while ((env->zero)-- && (i < env->sz))
		print[i++] = '0';
	if (!(env->flags & NULPREC) && i <= env->sz)
	{
		while (*nb)
			print[i++] = *nb++;
	}
	while (env->space > 0 && (env->space)-- && i < env->sz)
		print[i++] = ' ';
	return (print);
}

int		ft_printnb(long long ival, t_printf *env)
{
	char		*print;
	int			i;
	int			len;

	correct_modif(env, &ival);
	if (ival == 0)
		zero(env);
	env->nb = ft_itoa_base(ival, 10);
	env->space = 0;
	env->zero = 0;
	env->len = ival == 0 && env->flags & NULPREC ? 0 : ft_strlen(env->nb);
	len = 0;
	size(ival, env, env->width, env->len);
	if (env->nb && (print = ft_strnew(env->sz)))
	{
		get_space_zero1(ival, env, env->width, env->prec);
		get_space_zero2(ival, env, env->width, env->prec);
		i = (env->flags & MINUS) ? 0 : 1;
		print = print ? fill_int(env->nb, env, print, i) : print;
		ft_putstr(print);
		len = ft_strlen(print);
		free(print);
		free(env->nb);
	}
	return (len);
}
