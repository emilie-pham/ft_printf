/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:37:41 by epham             #+#    #+#             */
/*   Updated: 2019/04/04 19:06:53 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_flags(char **p, t_printf *env)
{
	while (**p && (**p == ' ' || **p == '-' || **p == '+' || **p == '#' || **p == '0'))
	{
		if (**p == ' ')				/* + values start with ' ' */
			env->flags |= SPACE;
		if (**p == '-')				/* Left justify */
			env->flags |= MINUS;
		if (**p == '+')				/* show sign */
			env->flags |= PLUS;
		if (**p == '#')
			env->flags |= HASH;
		if (**p == '0')				/* fill largeur de champs with 0 */
			env->flags |= ZERO;
		(*p)++;
	}
}

int		get_width_prec(char **p)
{
	int i;

	i = 0;
	while (ft_isdigit(**p))
	{
		i = i * 10 + (**p - '0');
		(*p)++;
	}
	return (i);
}

void	get_modif(char **p, t_printf *env)
{
	while (**p && (**p == 'h' || **p == 'l' || **p == 'L' || **p == 'j'
		|| **p == 'z'))
	{
		if (**p == 'h')
		{
			if (env->flags & H)
				env->flags |= HH;
			env->flags |= H;
		}
		else if (**p == 'l')
		{
			if (env->flags & L)
				env->flags |= LL;
			env->flags |= L;
		}
		else if (**p == 'L')
			env->flags |= BIGL;
		else if (**p == 'j')
			env->flags |= J;
		else if (**p == 'z')
			env->flags |= Z;
		(*p)++;
	}
}

void	parse_flags(char **p, int *count, t_printf *env, va_list *ap)
{
	while (**p != '%' && **p)
	{
		ft_putchar(*(*p)++);
		(*count)++;
	}
	if (**p && **p == '%')
		(*p)++;
	get_flags(p, env);					/* FLAGS */
	env->width = **p == '*' ? va_arg(*ap, int) : get_width_prec(p);	/* WIDTH */
	if (**p == '*')
		(*p)++;
	if (env->width < 0)
		env->flags |= MINUS;
	env->width *= env->width < 0 ? -1 : 1;
	if (**p == '.')
	{
		(*p)++;
		env->flags |= PREC;
	}
	env->prec = **p == '*' ? va_arg(*ap, int) : get_width_prec(p);
	env->prec = env->prec < 0 ? 0 : env->prec;
	if (**p == '*')
		(*p)++;
	get_modif(p, env);
}