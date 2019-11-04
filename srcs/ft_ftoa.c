/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:10:15 by epham             #+#    #+#             */
/*   Updated: 2019/04/16 14:59:22 by epham            ###   ########.fr       */
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

	tmp_nb = 10 * (nb - (unsigned long long)nb);
	tmp_prec = prec;
	while (prec > 0 && tmp_prec-- != 0)
		tmp_nb = 10 * (tmp_nb - (unsigned long long)tmp_nb);
	if (tmp_nb > 5
		|| (tmp_nb == 5 && (unsigned long long)nb % 2 == 1 && prec == 0))
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

static char		*ft_itoa_round(long double n, char *number, int i, int exp)
{
	n = n - (unsigned long long)n;
	n = n * 10;
	--i;
	if ((unsigned long long)n >= 5)
	{
		if (n == 5)
		{
			if (number[exp + i] != '.' && number[exp + i] % 2 != 0)
				number[exp + i] = number[exp + i] + 1;
		}
		else if (number[exp + i] != '.')
			number[exp + i] = number[exp + i] + 1;
	}
	if (number[exp + i] == ':')
	{
		number[exp + i] = '9';
		while (number[exp + i] == '9' && number[exp + i] != '.')
		{
			number[exp + i] = '0';
			i--;
		}
		if (number[exp + i] != '.')
			number[exp + i] = number[exp + i] + 1;
	}
	return (number);
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
		print[exponent + 1 + i++] = '0' + (unsigned long long)(dec * 10);
		dec = dec * 10 - (unsigned long long)(dec * 10);
	}
	print[exponent] = '.';
	print = fill_ent(print, exponent, ent);
	print = ft_itoa_round(dec, print, i + 1, exponent);
	return (print);
}
