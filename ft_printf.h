/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 06:58:16 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/18 08:35:22 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#	define FT_PRINTF_H
#	include <stdarg.h>
#	include <stdio.h>
#	include <stdlib.h>
#	include "libft/libft.h"

typedef struct		s_spec
{
	char			type;
}					t_specifier;
int		ft_printf(const char *f, ...);
#endif
