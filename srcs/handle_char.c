/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:52:37 by epham             #+#    #+#             */
/*   Updated: 2019/04/15 19:09:16 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_size_space_zero(int cval, t_printf *env)
{
	env->sz = env->width > 0 ? env->width - 1 : 0;
	env->space = env->sz;
	env->zero = cval == '%' && env->flags & ZERO
	&& !(env->flags & MINUS) ? env->space : 0;
	env->space = env->zero > 0 ? 0 : env->space;
}

char	*fill_char(t_printf *env, char *print, int lr)
{
	int i;

	i = 0;
	if (print)
	{
		while (lr == 1 && env->space && env->space--)
			print[i++] = ' ';
		while (env->zero && env->zero--)
			print[i++] = '0';
		while (env->space && env->space--)
			print[i++] = ' ';
	}
	return (print);
}

int		ft_printchar(int cval, t_printf *env)
{
	char	*print;
	int		i;
	int		len;

	len = 0;
	get_size_space_zero(cval, env);
	i = env->flags & MINUS ? 0 : 1;
	if ((print = ft_strnew(env->sz)))
	{
		print = fill_char(env, print, i);
		if (i == 0)
		{
			ft_putchar((unsigned char)cval);
			ft_putstr(print);
		}
		else
		{
			ft_putstr(print);
			ft_putchar((unsigned char)cval);
		}
		len = ft_strlen(print) + 1;
		if (print)
			free(print);
	}
	return (len);
}
