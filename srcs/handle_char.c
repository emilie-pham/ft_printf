/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:52:37 by epham             #+#    #+#             */
/*   Updated: 2019/04/05 11:50:23 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_char(int cval, t_printf *env, char *print, int lr)
{
	int i;

	i = 0;
	if (print)
	{
		while (lr == 1 && env->space && env->space--)
			print[i++] = ' ';
		while (env->zero && env->zero--)
			print[i++] = '0';
		print[i++] = (unsigned char)cval;
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
	int		j;

	j = 0;
	len = 0;
	env->sz = env->width > 1 ? env->width : 1;
	env->space = env->sz - 1;
	env->zero = cval == '%' && env->flags & ZERO
	&& !(env->flags & MINUS) ? env->space : 0;
	env->space = env->zero > 0 ? 0 : env->space;
	i = env->flags & MINUS ? 0 : 1;
	if ((print = ft_strnew(env->sz)))
	{
		print = fill_char(cval, env, print, i);
		ft_putstr(print);
		len = ft_strlen(print);
		if (cval == '\0')
			ft_putchar(cval);
		len = cval == '\0' ? 1 + len : len;
		free(print);
	}
	return (len);
}
