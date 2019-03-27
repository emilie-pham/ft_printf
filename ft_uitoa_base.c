/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:56:20 by epham             #+#    #+#             */
/*   Updated: 2019/03/26 16:09:51 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_uitoa_base(unsigned int value, int base)
{
	char    *s;
    long    n;
    int     i;

    n = value;
    i = 1;
    while ((n /= base) >= 1)
        i++;
    s = (char*)malloc(sizeof(char) * (i + 1));
    s[i] = '\0';
    n = value;
    while (i--)
    {
        s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
        n /= base;
    }
    return (s);
}