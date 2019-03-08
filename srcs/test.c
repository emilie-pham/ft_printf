#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>
#include "../Libft/libft.h"

/* Fonction pour print bits */

void    print_bits(unsigned char octet)
{
    int z = 128, oct = octet;

    while (z > 0)
    {
        if (oct & z)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        z >>= 1;
    }
    ft_putchar('\n');
}

/* minprintf: minimal printf with variable arg list */

void minprintf(char *fmt, ...)
{
	va_list ap; 							/* Points to each unnamed arg in turn */

	/**************************************/
	/*                                    */
	/*  p = pointer going through format. */
	/*  sval = string argument            */
	/*  cval = char argument			  */
	/*  ival = int argument 			  */
	/*									  */
	/**************************************/
	char 	*p, *sval, cval;
	int 	ival;
	// double dval;
	short	flags;						// short because 11 < 16 bits flags int ft_printf.h


	va_start(ap, fmt); 						/* make ap point to 1st unnamed argument */

	p = fmt;
	flags = 0;
	
	while (*p)
	{	
		/*******************************/
		/*							   */
		/*      print until first %    */
		/*							   */
		/*******************************/
		while (*p != '%' && *p)
		{
			ft_putchar(*p);
			p++;
		}
		p++;

		/*******************************/
		/*							   */
		/*          INDICATEUR         */
		/*							   */
		/*******************************/
		
		// Fonction qui prend en paramètre &p et qui incrêmente l'adresse au fur et à mesure

		while (*p && (*p == ' ' || *p == '-' || *p == '+' || *p == '#' || *p == '0'))
		{
			if (*p == ' ')				/* + values start with ' ' */
				flags |= SPACE;
			if (*p == '-')				/* Left justify */
				flags |= MINUS;
			if (*p == '+')				/* show sign */
				flags |= PLUS;
			if (*p == '#')
				flags |= HASHTAG;
			if (*p == '0')				/* fill largeur de champs with 0 */
				flags |= ZERO;
			p++;
		}

		/*******************************/
		/*                             */
		/* 			LARGEUR            */
		/*                             */
		/*******************************/

		// Fonction qui gère largeur de champs (ATOI) avec * EN OPTION
		
		/* OPTION
		
		if (*p && *p == '*')
		{
			

			if (*p == '*')
				flags |= STAR;
		
		}
		*/

		/*******************************/
		/*                             */
		/* 			PRECISION          */
		/*                             */
		/*******************************/
		if (*p == '.')
		{
			flags |= PRECISION;
			// fonction qui récupère valeur de précision avec atoi
		}

		/*******************************/
		/*                             */
		/* 			 LENGTH            */
		/*                             */
		/*******************************/

		while (*p && (*p == 'h' || *p == 'l' || *p == 'L'))
		{
			if (*p == 'h')
			{
				if (flags & H)
					flags ^= (HH);
				else
					flags |= H;
			}
			if (*p == 'l')
			{
				if (flags & L)
					flags |= LL;
				else
					flags |= L;
			}
			if (*p == 'L')
				flags |= BIGL;
			p++;
		}

		print_bits(flags);

		/*******************************/
		/*							   */
		/*             TYPE            */
		/*							   */
		/*******************************/
		if (*p == 'd')						/* digit */
		{
			ival = va_arg(ap, int);
			if (flags & PLUS)				/* if PLUS, turn of SPACE */
				flags &= ~SPACE;
			if (flags & (MINUS | PRECISION))
				flags &= ~ZERO;
			p++;
			continue;
		}
		if (*p == 'c')						/* char */
		{
			cval = va_arg(ap, int);
			ft_putchar(cval);
			p++;
			continue;
		}
		if (*p == 's')						/* string */
		{
			sval = va_arg(ap, char *);
			ft_putstr(sval);
			p++;
		}
	}
	ft_putchar('\n');
	va_end(ap); 							/* clean up when done */
}

int	main(void)
{
	// minprintf("% d", 20);
	printf("%010.15d\n", 20);
	return (0);
}
