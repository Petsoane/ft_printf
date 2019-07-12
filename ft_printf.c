/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 06:56:54 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/12 12:58:21 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_printf(char const *f, ...)
{
	va_list list;

	va_start(list, f);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			if  (parse_spec(&f, list) == -1)
				return (-1);
		}
		else
		{
			ft_putchar(*f);
			f++;
		}
	}
	return (0);
}

/*
 * This function takes a list and stores the flags in to the list and prints 
 * the value on the screen
 */
int		parse_spec(char const **f, va_list list)
{
	static	t_specifier spec;
	static char			id;

	if (get_id(*f, &id) == -1)
		return (-1);
	spec.field_width = NULL;
	spec.max_width = NULL;
	spec.flag = 0;
	if (get_format((char **)f, &spec) == -1)
		return (-1);
	print_specifier(id, &spec, list);
	(*f)++;
	return (0);
}

void	print_specifier(const char id, t_specifier *spec, va_list list)
{
	if (id == 'd' || id == 'D')
		print_type(spec, ft_itoa(va_arg(list, int)));
	else if (id == 's' || id == 'S')
		print_type(spec, va_arg(list, char *));
	else if (id == 'f' || id == 'F')
		print_float(spec, va_arg(list, double));
	else if (id == 'x' || id == 'X')
		print_conv(spec, va_arg(list, int), 16);
	else if (id == 'o' || id == 'O')
		print_conv(spec, va_arg(list, int), 8);
}
