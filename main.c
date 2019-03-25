/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:18:19 by epham             #+#    #+#             */
/*   Updated: 2019/03/25 15:25:18 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// printf("len = %d\n\n", ft_printf("my printf   :%+020d:\n", -5845));
	// ft_printf("my printf   :% -13d:\n", -5845);
	// printf("real printf :% -13d:\n\n", -5845);

	printf("%d\n", printf("%5%\n"));
	// printf("5 :%5%:\n");
	printf("%d\n", printf("%-5%\n"));
	// printf("-5 :%-5%:\n");
	printf("%d\n", printf("%.0%\n"));
	// printf(".0 :%.0%:\n");
	printf("%d\n", printf("%   %\n"));
	// printf("3 spaces :%   %:\n");
	return (0);
}
