/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:02:10 by epham             #+#    #+#             */
/*   Updated: 2019/04/04 19:16:30 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_type_dicsp(int *count, char **p, va_list *ap, t_printf *env)
{
	if (**p == 'd' || **p == 'D' || **p == 'i')
	{
		env->type = **p;
		*count += ft_printnb(va_arg(*ap, intmax_t), env);
		(*p)++;
	}
	else if (**p == 's')
	{
		*count += ft_printstr((const char *)va_arg(*ap, char *), env);
		(*p)++;
	}
	else if (**p == 'p')
	{
		env->type = **p;
		env->flags |= PREF;
		*count += ft_printuint((uintmax_t)va_arg(*ap, void *), env, 16);
		(*p)++;
	}
	else if (**p == 'c' || **p == '%')
	{
		*count += **p == '%' ? ft_printchar('%', env)
		: ft_printchar(va_arg(*ap, int), env);
		(*p)++;
	}
}

void	get_type_fuoxint(int *count, char **p, va_list *ap, t_printf *env)
{
	if (**p == 'o' || **p == 'O' || **p == 'u' || **p == 'U' || **p == 'x'
		|| **p == 'X')
	{
		env->type = **p;
		if (env->type == 'o' || env->type == 'O')
			*count += ft_printuint(va_arg(*ap, uintmax_t), env, 8);
		else if (env->type == 'x' || env->type =='X')
			*count += ft_printuint(va_arg(*ap, uintmax_t), env, 16);
		else
			*count += ft_printuint(va_arg(*ap, uintmax_t), env, 10);
		(*p)++;
	}
	else if (**p == 'f' || **p == 'F')
	{
		env->type = **p;
		*count += ft_printfloats(va_arg(*ap, double), env);
		(*p)++;
	}
}
