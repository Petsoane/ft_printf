/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:33:39 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/05 15:58:48 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#	define FT_PRINTF_H
#include <stdlib.h>
#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct			s_speciefier
{
	void				*data;
	size_t				type;
}						t_spec;
void		ft_printf(const char *s, ...);
int			count_arg(const char *s);

#endif
