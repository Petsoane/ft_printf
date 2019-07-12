/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 06:58:16 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/12 12:58:24 by lpetsoan         ###   ########.fr       */
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
int		parse_spec(char const **f, va_list list);
int		print_id(const char f, va_list list);
int		get_id(char const *, char *id);
int		get_format(char **f, t_specifier *spec);
int		valid_field(char *f);
int		valid_width(char *f);
int		valid_flag(char *f);
int		get_flag(char **f);
void	print_type(t_specifier *spec, char *val);
char	*get_field(char **f);
char	*get_width(char **f);
void	print_float(t_specifier *spec, double num);
void	spaces(int n, char padding);
void	print_specifier(char id, t_specifier *spec, va_list list);
void	print_conv(t_specifier *spec, int num, int base);
#endif
