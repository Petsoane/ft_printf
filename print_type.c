/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:40:43 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/12 12:29:32 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char *s, int max)
{
	while (max-- != 0)
		ft_putchar(*s++);
}

/* This function prints the first few parameters such as d and s */
void	print_type(t_specifier *spec, char *val)
{
	int		field;
	int		max_width;
	char	padding;

	padding = ' ';
	field = 1;
	max_width = ft_strlen(val);
	/* Check if the field width was set */
	if (spec->field_width != NULL)
		field = ft_atoi(spec->field_width);
	// check if the max width was set
	if (spec->max_width != NULL)
		max_width = ft_atoi(spec->max_width);
	// check if the padding with zeo flag was set.
	if (spec->flag & 1)
		padding = '0';	
	if (spec->flag & (1 << 3))
		if (val[0] != '-' && ft_isdigit(val[1]))
			ft_putchar(spec->flag & (1 << 4) ? '+' : ' ');

	field -= ft_strlen(val);
	if (spec->flag & (1 << 1))
	{
		spaces(field, padding);
		print(val, max_width);
	}
	else
	{
		print(val, max_width);
		spaces(field, padding);
	}
}
