/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:52:50 by epham             #+#    #+#             */
/*   Updated: 2019/04/05 11:47:21 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	zero(t_printf *env)
{
	if (env->type != 'p')
	{
		if ((env->prec == 0) && env->flags & PREC)
			env->flags |= NULPREC;
		if ((env->prec == 0 || env->prec == 1) && (env->flags & HASH))
			env->flags |= NULHASH;
		if (env->flags & PREF)
		{
			env->preflen = 0;
			env->flags &= ~PREF;
		}
	}
	else
		env->flags |= NULPOINT;
}

void	size(long long nb, t_printf *env, int width, int len)
{
	int flags;

	flags = env->flags;
	env->sz = (width > env->prec) ? width : env->prec;
	env->sz = (len > env->sz) ? len : env->sz;
	if (env->sz == len && ((nb >= 0 && (flags & (PLUS | SPACE))
		&& env->prec == 0)
		|| (env->prec > 0 && env->prec < env->sz && (env->flags & SPACE))))
		env->sz = len + 1;
	if ((nb < 0 && (env->prec + 1) > env->sz)
		|| (nb >= 0 && (flags & (PLUS | SPACE)) && (env->prec + 1) > env->sz))
		env->sz = env->prec + 1;
	if (env->prec > 0 && env->prec > env->sz)
		env->sz = env->prec;
}

void	get_space_zero(long long ival, t_printf *env, int width, int prec)
{
	int len;

	len = env->len;
	if ((width > prec) && (prec >= len))
	{
		env->space = (ival < 0 || (ival > 0 && env->flags & PLUS))
		? width - prec - 1 : width - prec;
		env->zero = (ival < 0) ? prec - len + 1 : prec - len;
	}
	if ((width > len) && (len > prec))
	{
		env->zero = (env->flags & ZERO) ? width - len : 0;
		env->space = (env->flags & ZERO) ? 0 : width - len;
		if ((env->flags & PLUS) && ival > 0)
		{
			env->zero = (env->flags & ZERO) ? width - len - 1 : 0;
			env->space = (env->flags & ZERO) ? 0 : width - len - 1;
		}
		if (ival > 0 && (env->flags & SPACE) && env->zero)
			env->zero -= 1;
	}
	if (((prec > width) && (width > len)) || ((prec > width) && (prec > len)))
		env->zero = ival < 0 ? prec - len + 1 : prec - len;
	if (ival >= 0 && (env->flags & SPACE) && (env->sz == env->len + 1))
		env->space = 1;
}

char	*fill_int(char *nb, t_printf *env, char *print, int lr)
{
	int i;

	i = 0;
	while (lr == 1 && env->space > 0 && (env->space)--)
		print[i++] = ' ';
	if (env->flags & SPACE && env->space > 0 && (env->space)--)
		print[i++] = ' ';
	else if (env->flags & PLUS)
		print[i++] = '+';
	else if (nb[0] == '-')
	{
		nb++;
		print[i++] = '-';
	}
	while ((env->zero)--)
		print[i++] = '0';
	if (!(env->flags & NULPREC))
	{
		while (*nb)
			print[i++] = *nb++;
	}
	while (env->space > 0 && (env->space)--)
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
	if ((print = ft_strnew(env->sz)))
	{
		get_space_zero(ival, env, env->width, env->prec);
		i = (env->flags & MINUS) ? 0 : 1;
		print = print ? fill_int(env->nb, env, print, i) : print;
		ft_putstr(print);
		len = ft_strlen(print);
		free(print);
		free(env->nb);
	}
	return (len);
}
