/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:18:19 by epham             #+#    #+#             */
/*   Updated: 2019/04/05 15:26:14 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

#include <float.h>

#include <limits.h>

int	main(void)
{
	// ft_printf("my printf   :%lf:\n", DBL_MAX);
	// printf("real printf :%lf:\n", DBL_MAX);

	// ft_printf("my printf   :%f %F:\n", 1.42, 1.42);
	// ft_printf("%o %o %o %o %o\n", 1, 100, 999, 42, 999988888);
	// ft_printf("%o%o%o%o%o\n\n", 1, 100, 999, 42, 999988888);

	// ft_printf("%d %d %d %d %d\n", 1, 100, 999, 42, 999988888);
	// ft_printf("%d%d%d%d%d\n\n", 1, 100, 999, 42, 999988888);

	// ft_printf("%s %s %s %s %s\n", "salut", "comment", "ca", "va", "?");
	// ft_printf("%s%s%s%s%s\n\n", "salut", "comment", "ca", "va", "?");

	// ft_printf("%p %p %p %p %p\n", ptr, ptr, ptr, ptr, ptr);
	// ft_printf("%p%p%p%p%p\n", ptr, ptr, ptr, ptr, ptr);
	char c = 'a';
	ft_printf("s:bonjour:%s.d:42:%d.p:'a':%p.pc:%%.S:暖炉:%S.D:longmax:%D.i:42:%i.o:42:%o.O:42:%O.u:100000:%u.U:ulongmax:%U.x:42:%x.X:42:%X.c:c:%c.C:플:%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	

	// printf("real printf :%f %F:\n", 1.42, 1.42);
	
	// printf("real printf :%#.1o:\n", 0);
	// ft_printf("my printf   :%#.1o:\n", 0);

	// printf("real printf :%U:\n", 4294967296);
	// ft_printf("my printf   :%U:\n", 4294967296);

	return (0);
}