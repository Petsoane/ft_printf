/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countspec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:49:49 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/05 15:58:54 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	valid_specifier(const char c);
static int	valid_flag(const char c);

int			count_arg(const char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!valid_specifier(*s))
			{
				if (!valid_flag(*s))
					return (-1);
				else 
				{
					s++;
					continue;
				}
			}
			else 
				count++;
		}
		s++;
	}
	return (count);
}

static int	valid_specifier(const char c)
{
	static const char *V_SPEC;

	V_SPEC = "sSpdDioOuUxXcC";
	while(*V_SPEC)
	{
		if (*V_SPEC == c)
			return (1);
		V_SPEC++;
	}
	return (0);
}

static int	valid_flag(const char c)
{
	static const char *V_FLAG;
	
	V_FLAG = "#0-+ ";
	while (*V_FLAG)
	{
		if (*V_FLAG == c)
			return (1);
		V_FLAG++;
	}
	return (0);
}
