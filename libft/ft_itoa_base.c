/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:35:12 by epham             #+#    #+#             */
/*   Updated: 2019/03/25 17:55:20 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_itoa_base(int value, int base)
{
    char    *s;
    long    n;
    int     sign;
    int     i;

    n = (value < 0) ? -(long)value : value;
    sign = (value < 0 && base == 10) ? -1 : 0;
    i = (sign == -1) ? 2 : 1;
    while ((n /= base) >= 1)
        i++;
    s = (char*)malloc(sizeof(char) * (i + 1));
    s[i] = '\0';
    n = (value < 0) ? -(long)value : value;
    while (i-- + sign)
    {
        s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
        n /= base;
    }
    (i == 0) ? s[i] = '-' : 0;
    return (s);
}
