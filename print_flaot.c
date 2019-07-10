/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flaot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:25:15 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/09 15:12:00 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_float(t_specifier *spec, double num)
{
	int		field;
	int		max_width;
	int		precision;

	precision = 1;
	field = 10;
	max_width = 1000;
	if (spec->field_width != NULL)
		field = ft_atoi(spec->field_width);
	if (spec->max_width != NULL)
		max_width = ft_atoi(spec->max_width);
	while (max_width >= 0)
	{
		precision *= 10;
		max_width--;
	}
	ft_putfloat(num, precision);
}
