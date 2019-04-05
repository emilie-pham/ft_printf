/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:00 by epham             #+#    #+#             */
/*   Updated: 2019/04/04 19:06:40 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* minprintf: minimal printf with variable arg list */

int ft_printf(char *fmt, ...)
{
	va_list ap;

	char 			*p;
	int 			count;
	t_printf		*env;

	va_start(ap, fmt);
	p = fmt;
	count = 0;
	if (!(env = malloc(sizeof(t_printf))))
		return (0) ;
	while (*p)
	{
		env->zero = 0;
		env->space = 0;
		env->sz = 0;
		parse_flags(&p, &count, env, &ap);
		get_type_dicsp(&count, &p, &ap, env);
		get_type_fuoxint(&count, &p, &ap, env);
	}
	free(env);
	va_end(ap); 							/* clean up when done */
	return (count);
}
