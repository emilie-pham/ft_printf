/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:21:02 by epham             #+#    #+#             */
/*   Updated: 2019/03/25 13:33:08 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void printBits(unsigned int num)
{
   const int bit_cnt = sizeof(unsigned int) * 8;
   unsigned int mask = (1 << (bit_cnt - 1));

   do
   {
      printf("%u", (num & mask) != 0?1:0);
      mask >>= 1;
   } while (mask > 0);
}

/* LARGEUR ET PRECISION */
size_t	get_width_prec(char **p)
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

void	get_modif(char **p, int flags)
{
	while (**p && (**p == 'h' || **p == 'l' || **p == 'L'))
	{
		if (**p == 'h')
		{
			if (flags & H)
				flags |= HH;
			flags |= H;
		}
		if (**p == 'l')
		{
			if (flags & L)
				flags |= LL;
			flags |= L;
		}
		if (**p == 'L')
			flags |= BIGL;
		(*p)++;
	}
}

int 	correct_flags_int(int ival, int flags)
{
	// printf("before correct : \n");
	// printBits(flags);

	if (flags & PLUS)		/* if PLUS, turn of SPACE */
		flags &= ~SPACE;
	if (flags & (MINUS | PRECISION))
		flags &= ~ZERO;
	if (ival < 0 && (flags & (PLUS | SPACE)))
		flags &= ~(PLUS | SPACE);				/*  */
	// printf("after correct : \n");
	// printBits(flags);
	return (flags);
}

/* FUNCTION THAT GETS SIZE OF STRING NEEDED */
size_t	size(int nb, t_printf *store, size_t len)
{
	size_t 	sz;
	size_t 	width;
	size_t 	prec;
	int		flags;

	flags = store->flags;
	width = store->width;
	prec = store->precision;
	sz = (width > len) ? width : len; 
	if (sz == width)
	{
		if (prec == 0 || (nb < 0 && (prec + 1) <= sz) || (prec > 0 && prec < sz) 
			|| (nb >= 0 && (flags & (PLUS | SPACE)) && (prec + 1) <= sz))
			return (width);
		if ((nb < 0 && (prec + 1) > sz)
			|| (nb >= 0 && (flags & (PLUS | SPACE)) && (prec + 1) > sz))
			return (prec + 1);
		if (prec > 0 && prec > sz)
			return (prec);
	}
	else if (sz == len)
	{
		if ((nb >= 0 && (flags & (PLUS | SPACE)) && prec == 0)
			|| (prec > 0 && prec < sz && (store->flags & SPACE)))
			return (len + 1);
		if (prec == 0 || (nb < 0 && (prec + 1) <= sz) || (prec > 0 && prec < sz)
			|| (nb >= 0 && (flags & (PLUS | SPACE)) && (prec + 1) <= sz))
			return (len);
		if ((nb < 0 && (prec + 1) > sz) 
			|| (nb >= 0 && (flags & (PLUS | SPACE)) && (prec + 1) > sz))
			return (prec + 1);
		if (prec > 0 && prec > sz)
			return (prec);
	}
	return (sz);
}

/* FUNCTION THAT GETS NUMBER OF ZEROS AND SPACES TO PRINT */
void	get_space_zero(int ival, t_printf *store, size_t width, size_t prec)
{
	size_t len;

	len = store->len;
	store->space = 0;
	store->zero = 0;
	if ((width > prec) && (prec > len))
	{
		store->space = width - prec;
		store->zero = prec - len;
		if (ival < 0)
		{
			store->space = width - prec - 1;
			store->zero = prec - len + 1;
		}
	}
	if ((width > len) && (len > prec))
	{
		store->zero = (store->flags & ZERO) ? width - len : 0;
		store->space = (store->flags & ZERO) ? 0 : width - len;
		if ((store->flags & PLUS) && ival > 0)
		{
			store->zero = (store->flags & ZERO) ? width - len - 1: 0;
			store->space = (store->flags & ZERO) ? 0 : width - len - 1;		/* if zeros then no space */
		}
		if (ival > 0 && store->space && (store->flags & SPACE))	/* remove space  */
			store->space -= 1;
		if (ival > 0 && (store->flags & SPACE))
			store->zero -= 1;
	}
	if (((prec > width) && (width > len)) || ((prec > width) && (prec > len)))
	{
		store->zero = prec - len;
		if (ival < 0)
			store->zero += 1;
	}
	/* if nb > 0 and SIZE = nblen */
	if (ival > 0 && (store->flags & SPACE) && (store->sz == store->len + 1))
		store->space = 1;
	// printf("zero = %zu\n", store->zero);
	// printf("space = %zu\n", store->space);
	// printf("nblen = %zu\n", store->len + store->space + store->zero);
}
