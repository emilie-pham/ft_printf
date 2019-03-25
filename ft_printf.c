/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:42:00 by epham             #+#    #+#             */
/*   Updated: 2019/03/25 13:33:17 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* minprintf: minimal printf with variable arg list */

int ft_printf(char *fmt, ...)
{
	va_list ap; 								/* Points to each unnamed arg in turn */

	char 			*p, *sval, cval;
	int 			ival, count;
	unsigned int	xval;
	t_printf		*store;

	va_start(ap, fmt);							/* make ap point to 1st unnamed argument */
	p = fmt;
	count = 0;
	if (!(store = malloc(sizeof(t_printf))))	/* Initialize the structure */
		return (0) ;
	store->flags = 0; 							/* Initialize the variable flags */
	while (*p)
	{	
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
				store->flags |= SPACE;
			if (*p == '-')				/* Left justify */
				store->flags |= MINUS;
			if (*p == '+')				/* show sign */
				store->flags |= PLUS;
			if (*p == '#')
				store->flags |= HASHTAG;
			if (*p == '0')				/* fill largeur de champs with 0 */
				store->flags |= ZERO;
			p++;
		}

		/* 			LARGEUR            */
		store->width = get_width_prec(&p);	/* Recupere valeur largeur avec * EN OPTION */
		
		/* OPTION
		if (*p && *p == '*')
			store->flags |= STAR;
		*/

		/* 			PRECISION          */
		if (*p == '.')
		{
			p++;
			store->flags |= PRECISION;		/* Recupere valeur precision */
		}
		store->precision = get_width_prec(&p);

		/* 		LENGTH	MODIF          */
		get_modif(&p, store->flags);

		/*             TYPE            */
		if (*p == 'd' || *p == 'i')
		{
			ival = va_arg(ap, int);
			store->flags = correct_flags_int(ival, store->flags);
			if (store->flags & HH)
				ival = (char)ival;
			if (store->flags & H)
				ival = (short int)ival;
			if (store->flags & L)
				ival = (long int)ival;
			if (store->flags & LL)
				ival = (long long int)ival;
			if (store->flags & BIGL)
				ival = (long double)ival;
			count += ft_printnb(ival, store, &count);
			p++;
			continue ;
		}
		else if (*p == 'o' || *p == 'u' || *p == 'x' || *p == 'X')
		{
			xval = va_arg(ap, unsigned int);
		}
		else if (*p == 'c')
		{
			cval = va_arg(ap, int);
			ft_putchar(cval);
			p++;
			continue;
		}
		else if (*p == 's')
		{
			sval = va_arg(ap, char *);
			ft_putstr(sval);
			p++;
			continue;
		}
	}
	va_end(ap); 							/* clean up when done */
	return (count);
}

