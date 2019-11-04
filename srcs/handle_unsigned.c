/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:35:46 by epham             #+#    #+#             */
/*   Updated: 2019/04/15 19:20:07 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	u_size(t_printf *env, int width, int prec, int len)
{
	int flags;

	flags = env->flags;
	env->sz = (width > prec) ? width : prec;
	env->sz = (len > env->sz) ? len : env->sz;
	if (prec > 0 && prec > env->sz)
		env->sz = prec;
	if (env->sz < len + env->preflen)
		env->sz = len + env->preflen;
	if ((env->flags & HASH)
		&& (len + env->preflen) > env->sz && env->nb[0] != '0')
		env->sz = len + env->preflen;
	if (env->sz < env->preflen + prec)
		env->sz = env->preflen + prec;
}

void	us_uz_zeroprec(t_printf *env, int sz, int len)
{
	env->zero = (env->flags & ZERO) && (env->sz > (len + env->preflen))
	? sz - len : 0;
	env->space = (env->flags & ZERO) ? 0 : sz - len;
	if (env->type == 'o')
	{
		env->zero += !env->zero
		&& (env->flags & HASH || (env->flags & NULHASH)) ? 1 : 0;
		env->space -= env->space
		&& (env->flags & NULHASH || env->flags & HASH) && env->zero ? 1 : 0;
		if (!(env->flags & ZERO) && !(env->flags & NULPREC)
			&& env->zero == 1 && env->nb[0] == '0')
		{
			env->zero = 0;
			env->space++;
		}
	}
	else if (env->type == 'x' || env->type == 'X' || env->type == 'p')
	{
		env->zero -= (env->zero > env->preflen) ? env->preflen : 0;
		env->space = (env->flags & NULPREC) ? env->sz : env->space;
	}
}

void	get_uspace_uzero(t_printf *env, int width, int len, int prec)
{
	env->space = (width >= prec) && (prec >= len) ? width - prec : 0;
	env->zero = (width >= prec) && (prec >= len) ? prec - len : 0;
	if ((width > len) && (len >= prec))
	{
		if (prec == 0)
			us_uz_zeroprec(env, env->sz, len);
		else if (prec > 0)
		{
			env->zero = (env->flags & HASH) && env->type == 'o' ? 1 : 0;
			env->space = (env->flags & HASH) && env->type == 'o'
			? width - len - 1 : width - len;
		}
	}
	else if (len >= width && len >= prec)
	{
		env->zero = (env->flags & HASH) && !(env->flags & PREF) ? 1 : 0;
		env->space = (env->flags & NULPREC) && (env->type == 'u') ? 1 : 0;
	}
	env->zero = (prec > width && prec > len) ? prec - len : env->zero;
	env->space -= (env->flags & PREF && env->space >= 1) ? env->preflen : 0;
}

char	*fill_uint(char *nb, t_printf *env, char *print, int lr)
{
	int i;

	i = 0;
	while (lr == 1 && env->space > 0 && (env->space)--)
		print[i++] = ' ';
	if (env->flags & PREF)
	{
		print[i++] = '0';
		print[i++] = 'X';
	}
	while (i < env->sz && (env->zero)--)
		print[i++] = '0';
	if (!((env->flags & NULPREC) || (env->flags & NULHASH)) || env->type == 'p')
	{
		while (*nb)
			print[i++] = *nb++;
	}
	while (i < env->sz && env->space > 0 && (env->space)--)
		print[i++] = ' ';
	return (print);
}

int		ft_printuint(unsigned long long ival, t_printf *env, int base)
{
	char	*print;
	int		len;

	correct_umodif(env, &ival);
	if (ival == 0)
		zero(env);
	env->nb = ft_uitoa_base(ival, base);
	env->len = ival == 0 && env->flags & NULPREC ? 0 : ft_strlen(env->nb);
	env->type = (env->type == 'o' || env->type == 'O') ? 'o' : env->type;
	len = 0;
	u_size(env, env->width, env->prec, env->len);
	if ((env->nb) && (print = ft_strnew(env->sz)))
	{
		if (env->sz > 0)
			get_uspace_uzero(env, env->width, env->len, env->prec);
		print = fill_uint(env->nb, env, print, (env->flags & MINUS) ? 0 : 1);
		if (env->type == 'x' || env->type == 'p')
			ft_strlower(print);
		ft_putstr(print);
		len = ft_strlen(print);
		free(print);
		free(env->nb);
	}
	return (len);
}
