/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 06:56:54 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/04 08:06:49 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_spec(const char **f, va_list list);
int		print_id(const char f, va_list list);

int		ft_printf(char const *f, ...)
{
	va_list list;

	va_start(list, f);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			if  (print_spec(&f, list) == -1)
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


int		print_spec(char const **f, va_list list)
{
	if (print_id(**f, list) == -1)
		return (-1);
	(*f)++;
	return (0);
}

int print_id(const char f, va_list list)
{
	if (f == 'i' || f == 'd' || f == 'D')
	{
		ft_putnbr(va_arg(list , int));
		return (0);
	}
	else if (f == 'f' || f == 'F')
	{
		ft_putfloat(va_arg(list, double), 10000);
		return (0);
	}
	else if (f == 's' || f == 'S')
	{
		ft_putstr(va_arg(list, char *));
		return (0);
	}
	else if (f == 'c' || f == 'C')
	{
		ft_putchar(va_arg(list, int));
		return (0);
	}
	else if (f == 'o' || f == 'O')
	{
		ft_baseconv(va_arg(list, int), 8);
		return (0);	
	}
	return (-1);
}

