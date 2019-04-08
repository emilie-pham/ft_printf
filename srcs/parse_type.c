/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:02:10 by epham             #+#    #+#             */
/*   Updated: 2019/04/08 11:10:42 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_type_dicsp(int *count, char **p, va_list *a, t_printf *env)
{
	if (**p == 'd' || **p == 'D' || **p == 'i')
	{
		env->type = **p;
		*count += ft_printnb(va_arg(*a, long long), env);
		(*p)++;
	}
	else if (**p == 's' || **p == 'S')
	{
		*count += ft_printstr((const char *)va_arg(*a, char *), env);
		(*p)++;
	}
	else if (**p == 'p')
	{
		env->type = **p;
		env->flags |= PREF;
		*count += ft_printuint((unsigned long long)va_arg(*a, void*), env, 16);
		(*p)++;
	}
	else if (**p == 'c' || **p == 'C' || **p == '%')
	{
		*count += **p == '%' ? ft_printchar('%', env)
		: ft_printchar(va_arg(*a, int), env);
		(*p)++;
	}
}

void	get_type_fuoxint(int *count, char **p, va_list *ap, t_printf *env)
{
	env->type = **p;
	if (**p == 'o' || **p == 'O' || **p == 'u'
		|| **p == 'U' || **p == 'x' || **p == 'X')
	{
		if (env->type == 'o' || env->type == 'O')
			*count += ft_printuint(va_arg(*ap, unsigned long long), env, 8);
		else if (env->type == 'x' || env->type == 'X')
			*count += ft_printuint(va_arg(*ap, unsigned long long), env, 16);
		else if (env->type == 'b')
			*count += ft_printuint(va_arg(*ap, unsigned long long), env, 2);
		else
			*count += ft_printuint(va_arg(*ap, unsigned long long), env, 10);
		(*p)++;
	}
	else if (**p == 'f' || **p == 'F')
	{
		*count += ft_printfloats(va_arg(*ap, double), env);
		(*p)++;
	}
}
