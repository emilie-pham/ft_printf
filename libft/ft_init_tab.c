/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:29:59 by anradix           #+#    #+#             */
/*   Updated: 2018/12/21 16:00:17 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_init_tab(size_t y, size_t x, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (y + 1))))
		return (NULL);
	while (i < y)
	{
		j = 0;
		if (!(tab[i] = (char *)malloc(sizeof(char) * (x + 1))))
			return (0);
		while (j < x)
		{
			tab[i][j] = c;
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
