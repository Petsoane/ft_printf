/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:17:56 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/09 16:02:02 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(t_specifier *spec, int num)
{
	int field;
	int	max_width;

	field = 10;
	max_width = 1000000;
	if (spec->field_width != NULL)
		field = ft_atoi(spec->field_width);
	if (spec->max_width != NULL)
		max_width = ft_atoi(spec->max_width);
	field -= ft_dlen(num);
	if (spec->flag & (1 << 1))
	{
		spaces(field);
		ft_baseconv(num, 16);
	}
	else
	{
		ft_baseconv(num, 16);
		spaces(field);
	}
}
