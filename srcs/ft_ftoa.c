/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:10:15 by epham             #+#    #+#             */
/*   Updated: 2019/04/04 12:21:16 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				get_exponent(unsigned long long nb)
{
	int	exponent;

	exponent = 0;
	while (nb != 0)
	{
		nb /= 10;
		exponent++;
	}
	return (exponent);
}

long double		round_up_down(long double nb, size_t prec)
{
	long double		tmp_nb;
	size_t			tmp_prec;

	tmp_nb = 10 * (nb - (int)nb);
	tmp_prec = prec;
	while (tmp_prec-- != 0)
		tmp_nb = 10 * (tmp_nb - (int)tmp_nb);
	if (tmp_nb > 5 || (tmp_nb == 5 && (int)nb % 2 == 1 && prec == 0))
		nb += 1 / ft_power(10, (prec));
	return (nb);
}

char			*fill_ent(char *print, int exponent, unsigned long long ent)
{
	while (ent > 0)
	{
		print[exponent - 1] = '0' + (ent % 10);
		ent /= 10;
		exponent--;
	}
	return (print);
}

char			*ft_ftoa(long double nb, int pr)
{
	unsigned long long	ent;
	long double			dec;
	int					exponent;
	char				*print;
	int					i;

	nb = round_up_down(nb, pr);
	ent = (unsigned long long)nb;
	dec = nb - ent;
	exponent = get_exponent(nb);
	exponent = (exponent == 0) ? 1 : exponent;
	print = ft_strnew(exponent + pr + 2);
	i = 0;
	print[0] = '0';
	while (i < pr)
	{
		print[exponent + 1 + i++] = '0' + (int)(dec * 10);
		dec = dec * 10 - (int)(dec * 10);
	}
	print[exponent] = '.';
	print = fill_ent(print, exponent, ent);
	return (print);
}