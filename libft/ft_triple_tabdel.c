/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triple_tabdel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:23:51 by epham             #+#    #+#             */
/*   Updated: 2018/12/21 13:22:55 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_triple_tabdel(char ***tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			ft_tabdel(tab[i]);
			i++;
		}
		free(tab);
	}
}
