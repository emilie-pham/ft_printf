/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:58:48 by epham             #+#    #+#             */
/*   Updated: 2018/12/19 08:59:19 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tablen(char **tab)
{
	unsigned int len;

	len = 0;
	if (!tab)
		return (0);
	while (tab[len])
		len++;
	return (len);
}