/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:34:08 by epham             #+#    #+#             */
/*   Updated: 2019/03/28 18:29:21 by epham            ###   ########.fr       */
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
#define	HASH		(1 << 3)
#define NULHASH		(1 << 4)
#define	ZERO		(1 << 5)
// LARGEUR DE CHAMPS
#define STAR		(1 << 6)
// PRECISION
#define	PREC		(1 << 7)
#define NULPREC		(1 << 8)
// MODIFICATEUR
#define H 			(1 << 9)
#define L 			(1 << 10)
#define BIGL		(1 << 11)
#define HH 			(1 << 12)
#define LL 			(1 << 13)
#define J			(1 << 14)
#define Z 			(1 << 15)
// CAS SPECIAUX
#define PREF		(1 << 16)

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#include "libft/libft.h"

typedef struct		s_printf
{
	int 			flags;
	size_t			width;
	size_t			prec;
	size_t			len;
	size_t 			space;
	size_t 			zero;
	size_t 			sz;
	size_t 			preflen;
	char 			type;
}					t_printf;

void printBits(unsigned int num);

int 	ft_printf(char *fmt, ...);
size_t	get_width_prec(char **p);
void	get_modif(char **p, t_printf *env);
int 	correct_flags_int(int ival, t_printf *env);
void	correct_modif(t_printf *env, intmax_t *val);
void	correct_umodif(t_printf *env, uintmax_t *val);
char    *ft_itoa_base(intmax_t value, int base);
char    *ft_uitoa_base(uintmax_t value, int base);
void	zero(t_printf *env);
int		ft_printnb(intmax_t ival, t_printf *env);
int		ft_printoct(uintmax_t ival, t_printf *env, int *count, int base);

#endif
