/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:24:40 by epham             #+#    #+#             */
/*   Updated: 2019/04/15 19:18:07 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	size_str(const char *sval, t_printf *env)
{
	int len;

	env->nb = sval == NULL ? ft_strdup("(null)") : ft_strdup(sval);
	len = sval == NULL && env->prec == 0
	&& env->flags & PREC ? 0 : ft_strlen(env->nb);
	len = env->prec && env->prec < len ? env->prec : len;
	env->sz = env->width > len ? env->width : len;
	env->space = env->sz > len ? env->sz - len : 0;
	env->space = env->flags & PREC && env->prec == 0 ? env->sz : env->space;
	env->zero = env->flags & ZERO ? env->space : 0;
	env->space = env->zero > 0 ? 0 : env->space;
}

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
	while (env->flags & ZERO && env->zero--)
		print[j++] = '0';
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

	printlen = 0;
	size_str(sval, env);
	i = env->flags & MINUS ? 0 : 1;
	if (env->prec == 0 && env->flags & PREC && env->width == 0)
		return (0);
	if ((print = ft_strnew(env->sz)))
	{
		print = fill_str(env->nb, env, print, i);
		ft_putstr(print);
		printlen = ft_strlen(print);
		free(print);
	}
	free(env->nb);
	return (printlen);
}
