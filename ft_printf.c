/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:00 by epham             #+#    #+#             */
/*   Updated: 2019/03/28 18:58:23 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* minprintf: minimal printf with variable arg list */

int ft_printf(char *fmt, ...)
{
	va_list ap; 								/* Points to each unnamed arg in turn */

	char 			*p, *sval, cval;
	int 			count;
	intmax_t		ival;
	uintmax_t		xval;
	t_printf		*env;

	va_start(ap, fmt);							/* make ap point to 1st unnamed argument */
	p = fmt;
	count = 0;
	if (!(env = malloc(sizeof(t_printf))))		/* Initialize the structure */
		return (0) ;
	while (*p)
	{	
		env->flags = 0;							/* Initialize the variable flags */
		env->space = 0;							/* initialize to 0 before calling get_uspace_uzero */
		env->zero = 0;
		/*      print until first %    */
		while (*p != '%' && *p)
		{
			ft_putchar(*p++);
			count++;
		}
		if (*p)									/* move after % to read flags or type */
			p++;
		if (*p && *p == '%')					/* CASE OF %% */
		{
			ft_putchar(*p++);
			count++;
		}

		/*          INDICATEUR         */
		while (*p && (*p == ' ' || *p == '-' || *p == '+' || *p == '#' || *p == '0'))
		{
			if (*p == ' ')				/* + values start with ' ' */
				env->flags |= SPACE;
			if (*p == '-')				/* Left justify */
				env->flags |= MINUS;
			if (*p == '+')				/* show sign */
				env->flags |= PLUS;
			if (*p == '#')
				env->flags |= HASH;
			if (*p == '0')				/* fill largeur de champs with 0 */
				env->flags |= ZERO;
			p++;
		}

		/* 			LARGEUR            */
		env->width = get_width_prec(&p);	/* Recupere valeur largeur avec * EN OPTION */
		
		/* OPTION
		if (*p && *p == '*')
			env->flags |= STAR;
		*/

		/* 			PRECISION          */
		if (*p == '.')
		{
			p++;
			env->flags |= PREC;		/* Recupere valeur precision */
		}
		env->prec = get_width_prec(&p);

		/* 		LENGTH	MODIF          */
		get_modif(&p, env);

		/*             TYPE            */
		if (*p == 'd' || *p == 'i')
		{
			ival = va_arg(ap, intmax_t);
			correct_modif(env, &ival);
			if (ival == 0)
				zero(env);
			count += ft_printnb(ival, env);
			p++;
			continue ;
		}
		else if (*p == 'o' || *p == 'u' || *p == 'x' || *p == 'X')
		{
			xval = va_arg(ap, uintmax_t);
			env->type = *p;
			// printBits(env->flags);
			// printf("\n\n");
			correct_umodif(env, &xval);
			if (xval == 0)
				zero(env);
			if (env->type == 'o')
				count += ft_printoct(xval, env, &count, 8);
			else if (env->type == 'x' || env->type =='X')
				count += ft_printoct(xval, env, &count, 16);
			else
				count += ft_printoct(xval, env, &count, 10);
			p++;
			continue ;
		}
		else if (*p == 'c')
		{
			cval = va_arg(ap, int);
			ft_putchar(cval);
			p++;
			continue ;
		}
		else if (*p == 's')
		{
			sval = va_arg(ap, char *);
			ft_putstr(sval);
			p++;
			continue ;
		}
	}
	free(env);
	va_end(ap); 							/* clean up when done */
	return (count);
}

