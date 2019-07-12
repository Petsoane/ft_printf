/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:17:56 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/12 12:29:34 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_conv(t_specifier *spec, int num, int base)
{
	int field;
	int	max_width;
	char padding;

	padding = ' ';
	field = 10;
	max_width = 1000000;
	if (spec->field_width != NULL)
		field = ft_atoi(spec->field_width);
	if (spec->max_width != NULL)
		max_width = ft_atoi(spec->max_width);
	if (spec->flag & 1)
		padding = '0';
	if (spec->flag& (1 << 3))
		if (num < 0)
			ft_putchar(spec->flag & (1 << 4) ? '+' : ' ');

	field -= ft_dlen(num);
	if (spec->flag & (1 << 1))
	{
		spaces(field, padding);
		if (spec->flag & 16)
			if (base == 2)
				ft_putstr("0b");
		ft_baseconv(num, base);
	}
	else
	{
		if (spec->flag & 16)
			if (base == 16)
				ft_putstr("0x");
		ft_baseconv(num, base);
		spaces(field, padding);
	}
}
