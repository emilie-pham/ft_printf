/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:34:08 by epham             #+#    #+#             */
/*   Updated: 2019/04/05 10:56:01 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPACE		(1 << 0)
# define MINUS		(1 << 1)
# define PLUS		(1 << 2)
# define HASH		(1 << 3)
# define NULHASH	(1 << 4)
# define ZERO		(1 << 5)

# define PREC		(1 << 6)
# define NULPREC	(1 << 7)

# define H			(1 << 8)
# define L			(1 << 9)
# define BIGL		(1 << 10)
# define HH			(1 << 11)
# define LL			(1 << 12)
# define J			(1 << 13)
# define Z			(1 << 14)

# define PREF		(1 << 15)
# define SIGN		(1 << 16)
# define NULPOINT 	(1 << 17)

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef struct	s_printf
{
	int			flags;
	int			width;
	int			prec;
	char		*nb;
	int			len;
	int			space;
	int			zero;
	int			sz;
	int			preflen;
	char		type;
}				t_printf;

int				ft_printf(char *fmt, ...);

void			parse_flags(char **p, int *count, t_printf *env, va_list *ap);
void			get_type_fuoxint(int *count, char **p, va_list *ap
	, t_printf *env);
void			get_type_dicsp(int *count, char **p, va_list *ap
	, t_printf *env);
void			correct_modif(t_printf *env, long long *val);
void			correct_umodif(t_printf *env, unsigned long long *val);
void			correct_fmodif(t_printf *env, long double *val);
void			zero(t_printf *env);

char			*ft_itoa_base(long long value, int base);
char			*ft_uitoa_base(unsigned long long value, int base);
char			*ft_ftoa(long double nb, int prec);

int				ft_printnb(long long ival, t_printf *env);
int				ft_printuint(unsigned long long ival, t_printf *env, int base);
int				ft_printfloats(long double fval, t_printf *env);
int				ft_printchar(int cval, t_printf *env);
int				ft_printstr(const char *sval, t_printf *env);

#endif
