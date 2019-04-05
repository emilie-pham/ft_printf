/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:24:40 by epham             #+#    #+#             */
/*   Updated: 2019/04/05 11:43:48 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_str(const char *str, t_printf *env, char *print, int lr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i == 1 && env->space && env->space--)
		print[j++] = ' ';
	while (lr == 1 && env->space && env->space--)
		print[j++] = ' ';
	while (str[i] && j < env->sz && ((env->prec && i < env->prec)
		|| !(env->flags & PREC)))
		print[j++] = str[i++];
	while (env->space && env->space--)
		print[j++] = ' ';
	return (print);
}

int		ft_printstr(const char *sval, t_printf *env)
{
	char	*print;
	int		i;
	int		printlen;
	int		len;

	if (sval == NULL)
		sval = "(null)";
	len = ft_strlen(sval);
	len = env->prec && env->prec < len ? env->prec : len;
	env->sz = env->width > len ? env->width : len;
	printlen = 0;
	env->space = env->sz > len ? env->sz - len : 0;
	i = env->flags & MINUS ? 0 : 1;
	if ((print = ft_strnew(env->sz)))
	{
		print = fill_str(sval, env, print, i);
		ft_putstr(print);
		printlen = ft_strlen(print);
		free(print);
	}
	return (printlen);
}
