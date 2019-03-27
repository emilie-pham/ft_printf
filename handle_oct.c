/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:35:46 by epham             #+#    #+#             */
/*   Updated: 2019/03/27 08:55:31 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* FUNCTION THAT GETS SIZE OF STRING NEEDED */
void	size_oct(t_printf *env, size_t width, size_t prec, size_t len)
{
	int		flags;

	flags = env->flags;
	env->sz = (width > len) ? width : len;
	if (env->sz == width)
	{
		if (prec == 0 || (prec > 0 && prec < env->sz))
			env->sz = width;
		if (prec > 0 && prec > env->sz)
			env->sz = prec;
	}
	else if (env->sz == len)
	{
		if (((flags & HASHTAG) && prec == 0)
			|| (prec > 0 && prec < env->sz && (env->flags & HASHTAG)))
			env->sz = len + 1;
		if (prec == 0 || (prec > 0 && prec < env->sz))
			env->sz = len;
		if (prec > 0 && prec > env->sz)
			env->sz = prec;
	}
	env->space = 0;			/* initialize to 0 before calling get_uspace_uzero */
	env->zero = 0;
}

/* FUNCTION THAT GETS NUMBER OF ZEROS AND SPACES TO PRINT */
void	get_uspace_uzero(t_printf *env, size_t width, size_t len, size_t prec)
{
	if ((width >= prec) && (prec >= len))
	{
		env->space = width - prec;
		env->zero = prec - len;
	}
	if ((width >= len) && (len >= prec))
	{
		if (prec == 0)
		{
			env->zero = (env->flags & HASHTAG) && !(env->flags & ZERO) ? 1 : 0;
			env->space = (env->flags & HASHTAG) && !(env->flags & ZERO) 
			? width - len - 1 : width - len;
			env->zero = (env->flags & ZERO) ? width - len : 0;
			env->space = (env->flags & ZERO) ? 0 : width - len;
		}
		else
		{
			env->zero = (env->flags & HASHTAG) ? 1 : 0;
			env->space = (env->flags & HASHTAG) ? width - len - 1 : width - len;
		}
	}
	if (len >= width && len >= prec)
		env->zero = (env->flags & HASHTAG) ? 1 : 0;
	if (prec >= width && prec >= len)
		env->zero = prec - len;
}

/* FUNCTION THAT FILLS IN THE PRINT STRING WITH CONVERTED NUMBER */
char *write_oct(char *nb, t_printf *env, char *print, int lr)
{
	int i;

	i = 0;
	if (lr == 0)
	{
		while ((env->zero)--)
			print[i++] = '0';
		while (*nb)
			print[i++] = *nb++;
		while ((env->space)--)
			print[i++] = ' ';
	}
	if (lr == 1)
	{
		while ((env->space)--)
			print[i++] = ' ';
		while ((env->zero)--)
			print[i++] = '0';
		while (*nb)
			print[i++] = *nb++;
	}
	return (print);
}

int	ft_printoct(unsigned int ival, t_printf *env, int *count)
{
	char	*print;
	char	*nb;
	size_t	i;
	size_t 	len;

	nb = ft_uitoa_base(ival, 8);
	env->len = ft_strlen(nb);
	size_oct(env, env->width, env->prec, env->len);
	// printf("env->sz = %zu\n", env->sz);
	print = ft_strnew(env->sz);
	get_uspace_uzero(env, env->width, env->len, env->prec);
	i = (env->flags & MINUS) ? 0 : 1;
	print = write_oct(nb, env, print, i);
	ft_putstr(print);
	len = ft_strlen(print);
	free(print);
	free(nb);
	return (len);
}

