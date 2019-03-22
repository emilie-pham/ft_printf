/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:52:50 by epham             #+#    #+#             */
/*   Updated: 2019/03/22 19:36:53 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *right(char *nb, t_printf *store, char *print)
{
	int i;

	// printf("size = %d\n", sz);
	// printf("zero = %zu\n", store->zero);
	// printf("spaces = %zu\n", store->space);
	i = 0;

	if ((store->flags & SPACE) && (store->sz != store->len + 1))
		store->space++;
	while ((store->space)--)
		print[i++] = ' ';
	if (nb[0] == '-')
	{
		nb++;
		print[i++] = '-';
	}
	else if (store->flags & PLUS)
		print[i++] = '+';
	while ((store->zero)--)
		print[i++] = '0';
	while (*nb)
		print[i++] = *nb++;
	return (print);
}

char *left(char *nb, t_printf *store, char *print)
{
	int i;

	i = 0;
	if (nb[0] == '-')
	{
		nb++;
		print[i++] = '-';
	}
	else if (store->flags & PLUS)
		print[i++] = '+';
	else if (store->flags & SPACE)
		print[i++] = ' ';
	while ((store->zero)--)
		print[i++] = '0';
	while (*nb)
		print[i++] = *nb++;
	while ((store->space)--)
		print[i++] = ' ';
	return (print);
}

int	ft_printnb(int ival, t_printf *store, int *count)
{
	char	*print;
	char	*nb;
	size_t		i;

	nb = ft_itoa_base(ival, 10);
	store->len = ft_strlen(nb);
	store->sz = size(ival, store, store->len);
	// printf("sz = %d\n", sz);
	print = ft_strnew(store->sz);
	get_space_zero(ival, store, store->width, store->precision);
	i = (store->flags & MINUS) ? 0 : store->sz - 1;
	if (i == 0)
		print = left(nb, store, print);
	else if (i == store->sz - 1)
		print = right(nb, store, print);
	ft_putstr(print);
	count += ft_strlen(print);
	return (ft_strlen(print));
}
