/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 06:58:16 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/09 16:02:04 by lpetsoan         ###   ########.fr       */
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
	char			*field_width;
	char			*max_width;
	int				flag;
}					t_specifier;
int		ft_printf(const char *f, ...);
int		validate(const char f, const char *fomr);
void	print_type(t_specifier *spec, char *val);
char	*get_field(char **f);
char	*get_width(char **f);
void	print_float(t_specifier *spec, double num);
void	print_hex(t_specifier *spec, int num);
void	spaces(int n );

#endif
