/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:40:43 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/09 15:18:22 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char *s)
{
	ft_putstr(s);
}

void	print_type(t_specifier *spec, char *val)
{
	int		field;
	int		max_width;
	
	field = 10;
	max_width = ft_strlen(val) + 100;
	if (spec->field_width != NULL)
		field = ft_atoi(spec->field_width);
	if (spec->max_width != NULL)
		max_width = ft_atoi(spec->max_width);
	field -= ft_strlen(val);
	puts("\nPrinting the valus");
	if (spec->flag & (1 << 1))
	{
		spaces(field);
		print(val);
	}
	else
	{
		print(val);
		spaces(field);
	}
}
