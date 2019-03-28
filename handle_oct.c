/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:35:46 by epham             #+#    #+#             */
/*   Updated: 2019/03/28 19:44:05 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* HANDLE ZERO VALUE CASE */
void	zero(t_printf *env)
{
	if (env->prec == 0 && env->flags & PREC)
		env->flags |= NULPREC;
	if ((env->width == 0 || env->width == 1) && env->prec == 0 && (env->flags & HASH))
		env->flags |= NULHASH;
	if (env->flags & PREF)
		env->flags &= ~PREF;
}

/* GET STRING SIZE NEEDED */
void	sz_oct(t_printf *env, size_t width, size_t prec, size_t len)
{
	int flags;

	flags = env->flags;
	env->sz = (width > prec) ? width : prec;		/* CHECK BIGGER, WIDTH OR PREC */
	env->sz = (len > env->sz) ? len : env->sz;		/* IF LEN > W or LEN > P, TAKE LEN */
	if (prec > 0 && prec > env->sz)
		env->sz = prec;
	if ((env->flags & HASH) && (env->len + env->preflen) > env->sz)
		env->sz = env->len + env->preflen;
	if ((env->flags & NULPREC || env->flags & NULHASH) && env->sz != 1)
		env->sz--;
}

/* GET NUMBER OF ZEROS AND SPACES TO PRINT */
void	get_uspace_uzero(t_printf *env, size_t width, size_t len, size_t prec)
{
	if ((width >= prec) && (prec >= len))
	{
		env->space = width - prec;
		env->zero = prec - len;
	}	
	if ((width > len) && (len > prec)) /* NEED W > L for w - l - 1 */
	{
		if (prec == 0)
		{
			/* Xx AND u */
			env->zero = (env->flags & ZERO)  && (env->sz > (len + env->preflen)) ? width - len : 0;
			env->space = (env->flags & ZERO) ? 0 : width - len;
			if (env->type == 'o')
			{
				env->zero = (env->flags & HASH) && !(env->flags & ZERO) ? 1 : 0;
				env->space = (env->flags & HASH) && !(env->flags & ZERO) 
				? width - len - 1 : width - len;
			}
			else if (env->type == 'x' || env->type == 'X')
				env->zero = (env->zero > env->preflen && (env->flags & PREF)) ? env->zero - env->preflen : env->zero;
		}
		else
		{
			env->zero = (env->flags & HASH) && !(env->flags & PREF) ? 1 : 0;
			env->space = (env->flags & HASH) ? width - len - 1 : width - len;
		}
	}
	else if (len >= width && len >= prec)
	{
		env->zero = (env->flags & HASH) && !(env->flags & PREF) ? 1 : 0;
		env->space = (env->flags & NULPREC) && (env->type == 'u') ? 1 : 0;
	}
	if (prec >= width && prec >= len)
		env->zero = prec - len;
	if (env->sz > len + env->preflen && env->flags & PREF && env->space > 1)
		env->space -= 2;
	if (env->sz == len + env->preflen && env->flags & PREF && env->zero > 1)
		env->zero -= 2;
}

/* FUNCTION THAT FILLS IN THE PRINT STRING WITH CONVERTED NUMBER */
char *write_oct(char *nb, t_printf *env, char *print, int lr)
{
	int i;

	i = 0;
	if (lr == 0)
	{
		if (env->flags & PREF)
			{
				print[i++] = '0';
				print[i++] = 'X';
			}
		while ((env->zero)--)
			print[i++] = '0';
		if (!((env->flags & NULPREC) || (env->flags & NULHASH)))
		{
			while (*nb)
				print[i++] = *nb++;
		}
		while ((env->space)--)
			print[i++] = ' ';
	}
	if (lr == 1)
	{
		while ((env->space)--)
			print[i++] = ' ';
		if (env->flags & PREF)
			{
				print[i++] = '0';
				print[i++] = 'X';
			}
		while ((env->zero)--)
			print[i++] = '0';
		if (!((env->flags & NULPREC) || (env->flags & NULHASH)))
		{
			while (*nb)
				print[i++] = *nb++;
		}
	}
	return (print);
}

int	ft_printoct(uintmax_t ival, t_printf *env, int *count, int base)
{
	char	*print;
	char	*nb;
	size_t	i;
	size_t 	len;

	nb = ft_uitoa_base(ival, base);
	env->len = ft_strlen(nb);
	sz_oct(env, env->width, env->prec, env->len);
	print = ft_strnew(env->sz);
	get_uspace_uzero(env, env->width, env->len, env->prec);
	i = (env->flags & MINUS) ? 0 : 1;
	print = write_oct(nb, env, print, i);
	if (env->type == 'x')
		ft_strlower(print);
	ft_putstr(print);
	len = ft_strlen(print);
	free(print);
	free(nb);
	return (len);
}

