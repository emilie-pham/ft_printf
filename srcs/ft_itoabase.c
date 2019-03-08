/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:35:12 by epham             #+#    #+#             */
/*   Updated: 2019/03/08 16:03:52 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Libft/libft.h"
#include <stdlib.h>
#include <string.h>

static int	ft_count(int n)
{
	int		i;
	size_t	neg;
	size_t	count;

	i = n;
	count = 1;
	neg = 0;
	if (i < 0)
		neg = 1;
	while (i /= 10)
		count++;
	return (count + neg);
}

char		*ft_itoabase(int n, int base)
{
	char	*s;
	int		count;
	size_t	neg;

	neg = 0;
	count = ft_count(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(s = ft_strnew(ft_count(n))))
		return (NULL);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (count > 0)
	{
		count--;
		s[count] = (n % 10) + '0';
		n /= 10;
	}
	if (neg == 1)
		s[0] = '-';
	return (s);
}
