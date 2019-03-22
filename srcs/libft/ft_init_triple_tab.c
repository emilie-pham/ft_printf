/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_triple_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 23:36:29 by anradix           #+#    #+#             */
/*   Updated: 2018/12/21 13:40:43 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	***ft_init_triple_tab(int nb_pattern, int x, int y, char c)
{
	char	***tab;
	int		i;

	i = 0;
	if (!(tab = (char ***)malloc(sizeof(char **) * nb_pattern + 1)))
		return (NULL);
	while (i < nb_pattern)
	{
		if (!(tab[i] = ft_init_tab(x, y, c)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
