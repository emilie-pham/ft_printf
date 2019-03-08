/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 19:23:54 by epham             #+#    #+#             */
/*   Updated: 2019/03/08 19:28:44 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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
// LARGEUR DE CHAMPS
#define STAR		(1 << 5)
// PRECISION
#define	PRECISION	(1 << 6)
// MODIFICATEUR
#define H 			(1 << 7)
#define L 			(1 << 8)
#define BIGL		(1 << 9)
#define HH 			(1 << 10)
#define LL 			(1 << 11)

#endif