/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:35:12 by epham             #+#    #+#             */
/*   Updated: 2019/03/25 14:37:21 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size(int value, int base)
{
	int count;

	count = 0;
	if (base != 10 && value < 0)
		value *= -1;
	if (base == 10 && value < 0)
	{
		count++;
		value *= -1;
	}
	while (value > 0)
	{
		count++;
		value /= base;
	}
	return (count);
}

char	*ft_itoa_base(int value, int base)
{
	int 	len;
	char	*radix;
	char	*ret;
	
	len = ft_size(value, base);
	radix = "0123456789ABCDEF";
	if (value == 0)
		return ("0");
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (base == 10 && value < 0)
		ret[0] = '-';
	ret[len] = '\0';
	if (value < 0)
		value *= -1;
	while (value > 0)
	{
		ret[len - 1] = radix[value % base];
		len--;
		value /= base;
	}
	return (ret);
}
