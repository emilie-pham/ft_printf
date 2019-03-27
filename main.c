/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:18:19 by epham             #+#    #+#             */
/*   Updated: 2019/03/27 09:29:37 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// ft_printf("my printf   :%#.o:\n", '\\xff');
	// printf("real printf :%#.o:\n", '\\xff');

	// ft_printf("my printf   :%#.0o:\n", '\\xff');
	// printf("real printf :%#.0o:\n", '\\xff');

	// ft_printf("my printf   :%#.1o:\n", '\\xff');
	// printf("real printf :%#.1o:\n", '\\xff');

	ft_printf("my printf   :% 10.10d:\n", 10);
	printf("real printf :% 10.10d:\n", 10);

	// printf("real printf :%3.15o:\n", 5845);
	// printf("real printf :%#03.15o:\n", 5845);
	// printf("real printf :%#.20o:\n", 5845);
	// printf("real printf :%.20o:\n", 5845);

	// printf("%d\n", printf("%5%\n"));
	// printf("5 :%5%:\n");
	// printf("%d\n", printf("%-5%\n"));
	// printf("-5 :%-5%:\n");
	// printf("%d\n", printf("%.0%\n"));
	// printf(".0 :%.0%:\n");
	// printf("%d\n", printf("%   %\n"));
	// printf("3 spaces :%   %:\n");
	return (0);
}
