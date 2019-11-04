/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:28:49 by epham             #+#    #+#             */
/*   Updated: 2019/04/16 11:48:33 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <wchar.h>

int		wchar_len(wchar_t wchar)
{
	if (wchar <= 0x7F)
		return (1);
	else if (wchar <= 0x7FF)
		return (2);
	else if (wchar <= 0xFFFF)
		return (3);
	else if (wchar <= 0x10FFFF)
		return (4);
	return (-1);
}

void	ft_putwchar(wchar_t wchar)
{
	if (wchar <= 0x7F)
		ft_putchar(wchar);
	else if (wchar <= 0x7FF)
	{
		ft_putchar((wchar >> 6) + 0xC0);
		ft_putchar((wchar & 0x3F) + 0x80);
	}
	else if (wchar <= 0xFFFF)
	{
		ft_putchar((wchar >> 12) + 0xE0);
		ft_putchar(((wchar >> 6) & 0x3F) + 0x80);
		ft_putchar((wchar & 0x3F) + 0x80);
	}
	else if (wchar <= 0x10FFFF)
	{
		ft_putchar((wchar >> 18) + 0xF0);
		ft_putchar(((wchar >> 12) & 0x3F) + 0x80);
		ft_putchar(((wchar >> 6) & 0x3F) + 0x80);
		ft_putchar((wchar & 0x3F) + 0x80);
	}
}

int		ft_printwchar(t_printf *env, wchar_t wchar)
{
	int			len;
	int			i;

	len = wchar_len(wchar);
	ft_putwchar(wchar);
	i = len;
	if (env->flags & MINUS)
	{
		while (i++ < env->width)
		{
			ft_putchar(' ');
			len++;
		}
	}
	return (len);
}
