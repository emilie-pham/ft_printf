/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:34:08 by epham             #+#    #+#             */
/*   Updated: 2019/03/22 19:23:36 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* 

DIFFERENT VARIABLE DEPENDING ON NUMBER OF BITS

8	bits 		UNSIGNED CHAR
16 	bits 		SHORT
32 	bits 		INT
64 	bits 		LONG

*/

// INDICATOR
#define SPACE		(1 << 0)
#define MINUS		(1 << 1)
#define PLUS		(1 << 2)
#define	HASHTAG		(1 << 3)
#define	ZERO		(1 << 4)
// #define PANDZ		(1 << 5)
// LARGEUR DE CHAMPS
#define STAR		(1 << 6)
// PRECISION
#define	PRECISION	(1 << 7)
// MODIFICATEUR
#define H 			(1 << 8)
#define L 			(1 << 9)
#define BIGL		(1 << 10)
#define HH 			(1 << 11)
#define LL 			(1 << 12)

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../Libft/libft.h"

typedef struct		s_printf
{
	int 			flags;
	size_t			width;
	size_t			precision;
	size_t			len;
	size_t 			space;
	size_t 			zero;
	size_t 			sz;
	char			type;
}					t_printf;

int 	ft_printf(char *fmt, ...);
size_t	get_width_prec(char **p);
void	get_modif(char **p, int flags);
int 	correct_flags_int(int ival, int flags);
char	*ft_itoa_base(int value, int base);
size_t	size(int ival, t_printf *store, size_t len);
void	get_space_zero(int ival, t_printf *store, size_t width, size_t prec);
int		ft_printnb(int ival, t_printf *store, int *count);

#endif
