/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:34:08 by epham             #+#    #+#             */
/*   Updated: 2019/04/04 15:15:09 by epham            ###   ########.fr       */
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
#define PREF		(1 << 16) /* UNSIGNED PREFIX # */
#define SIGN		(1 << 17) /* NEGATIVE FLOAT */
#define NULPOINT	(1 << 18)

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#include "../libft/libft.h"

typedef struct		s_printf
{
	int 			flags;
	int				width;
	int				prec;
	char 			*nb;
	int				len;
	int 			space;
	int 			zero;
	int 			sz;
	int 			preflen;
	char 			type;
}					t_printf;

void printBits(unsigned int num);

int 	ft_printf(char *fmt, ...);

void	parse_flags(char **p, int *count, t_printf *env, va_list *ap);
void	get_flags(char **p, t_printf *env);
int 	get_width_prec(char **p);
void	get_modif(char **p, t_printf *env);
void	get_type_fuoxint(int *count, char **p, va_list *ap, t_printf *env);
void	get_type_dicsp(int *count, char **p, va_list *ap, t_printf *env);
int 	correct_flags(long double ival, t_printf *env);
void	correct_modif(t_printf *env, intmax_t *val);
void	correct_umodif(t_printf *env, uintmax_t *val);
void	correct_fmodif(t_printf *env, long double *val);
void	zero(t_printf *env);

char    *ft_itoa_base(intmax_t value, int base);
char    *ft_uitoa_base(uintmax_t value, int base);
char	*ft_ftoa(long double nb, int prec);

int		ft_printnb(intmax_t ival, t_printf *env);
int		ft_printuint(uintmax_t ival, t_printf *env, int base);
int		ft_printfloats(long double fval, t_printf *env);
int		ft_printchar(int cval, t_printf *env);
int		ft_printstr(const char *sval, t_printf *env);

#endif
