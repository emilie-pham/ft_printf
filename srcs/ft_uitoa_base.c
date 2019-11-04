/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:56:20 by epham             #+#    #+#             */
/*   Updated: 2019/04/04 21:38:03 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_uitoa_base(unsigned long long value, int base)
{
	char				*s;
	unsigned long long	n;
	int					i;

	n = value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	if (!(s = ft_strnew(i)))
		return (NULL);
	s[i] = '\0';
	n = value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (s);
}
