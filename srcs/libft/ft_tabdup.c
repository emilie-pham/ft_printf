/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anradix <anradix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:05:33 by epham             #+#    #+#             */
/*   Updated: 2018/12/19 16:06:11 by anradix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	**ft_tabdup(char **tab, size_t start, size_t finish)
{
	char		**dup;
	size_t		i;

	i = start;
	if (finish < ft_tablen(tab))
	{
		if (!(dup = (char **)malloc(sizeof(char *) * (finish - start + 1) + 1)))
			return (NULL);
	}
	else
	{
		if (!(dup = (char **)malloc(sizeof(char *) * ft_tablen(tab) + 1)))
			return (NULL);
	}
	while (i < finish && tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		i++;
	}
	return (dup);
}
