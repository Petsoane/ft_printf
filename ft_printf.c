/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 06:56:54 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/18 09:58:38 by lpetsoan         ###   ########.fr       */
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
			if (*f == 'i' || *f == 'd' || *f == 'D')
				ft_putnbr(va_arg(list , int));
			else if (*f == 'f' || *f == 'F')
				ft_putfloat(va_arg(list, double));
			else if (*f == 's' || *f == 'S')
				ft_putstr(va_arg(list, char *));
			else if (*f == 'c' || *f == 'C')
				ft_putchar(va_arg(list, int));
			else if (*f == 'o' || *f == 'O')
				ft_putoctal(va_arg(list, int));
		}
		else
			ft_putchar(*f);
		f++;
	}
	return (0);
}
