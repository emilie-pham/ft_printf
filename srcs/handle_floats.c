/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:00:33 by epham             #+#    #+#             */
/*   Updated: 2019/04/08 11:08:16 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	f_size(t_printf *env)
{
	int	flags;

	flags = env->flags;
	env->sz = env->len > env->width ? env->len : env->width;
	if (env->sz == env->len
		&& (env->flags & SIGN || env->flags & (PLUS | SPACE)))
		env->sz = env->len + 1;
	if (env->sz == env->width && (env->flags & SIGN
		|| env->flags & (PLUS | SPACE)) && env->len + 1 > env->width)
		env->sz = env->width + 1;
	if (env->sz > env->width && env->prec == 0
		&& (env->flags & PREC) && !(env->flags & HASH))
		env->sz -= 1;
}

void	fspace_fzero(t_printf *env)
{
	int len;

	len = env->len;
	if (env->sz > len)
	{
		env->space = env->sz - len;
		env->space = (env->flags & SIGN || env->flags & PLUS)
		? env->space - 1 : env->space;
		if (env->prec == 0 && (env->flags & PREC) && !(env->flags & HASH))
			env->space += 1;
		env->zero = (env->flags & ZERO) ? env->space : 0;
		env->space = (env->flags & ZERO) ? 0 : env->space;
		if (env->flags & ZERO && (env->flags & SPACE))
		{
			env->space++;
			env->zero -= env->zero > 0 ? 1 : 0;
		}
	}
	else
		env->space = (env->flags & SPACE) ? 1 : 0;
}

char	*fill_floats(char *fl, t_printf *env, char *print, int lr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (lr == 1 && env->space > 0 && env->space--)
		print[i++] = ' ';
	if (env->flags & SPACE && env->space && env->space--)
		print[i++] = ' ';
	else if (env->flags & PLUS && !(env->flags & SIGN))
		print[i++] = '+';
	else if (env->flags & SIGN)
		print[i++] = '-';
	while (env->zero--)
		print[i++] = '0';
	while (i + j < env->sz && fl[j])
	{
		print[i + j] = fl[j];
		j++;
	}
	while (env->space > 0 && (env->space)--)
		print[i + j++] = ' ';
	return (print);
}

int		ft_printfloats(long double fval, t_printf *env)
{
	char	*print;
	int		i;
	int		len;

	len = 0;
	correct_fmodif(env, &fval);
	if (fval < 0 || fval == -0.0)
		env->flags |= SIGN;
	fval = fval < 0 ? -fval : fval;
	env->prec = !(env->flags & PREC) ? 6 : env->prec;
	env->nb = ft_ftoa(fval, env->prec);
	env->len = ft_strlen(env->nb);
	f_size(env);
	if ((print = ft_strnew(env->sz)))
	{
		fspace_fzero(env);
		i = (env->flags & MINUS) ? 0 : 1;
		print = fill_floats(env->nb, env, print, i);
		ft_putstr(print);
		len = ft_strlen(print);
		free(print);
		free(env->nb);
	}
	return (len);
}
