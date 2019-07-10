/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 06:56:54 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/09 16:01:59 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_spec(char const **f, va_list list);
int		print_id(const char f, va_list list);
int		get_id(char const *f, char *id);
int		get_format(char **f, t_specifier *spec);
void	print_specifier(char id, t_specifier *spec, va_list list);

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
		print_hex(spec, va_arg(list, int));
}



int		valid_field(char *f)
{
	if (!(*f >= '0' && *f <= '9'))
		return (0);
	return (1);
}

int		valid_width(char *f)
{
	if (*f == '.' && ft_isdigit(*(f + 1)))
		return (1);
	return (0);
}

int		valid_flag(char *f)
{
	const char *v_flag = "# -+0";
	
	while (*v_flag)
	{
		if (*v_flag == *f)
			return (1);
		v_flag++;
	}
	return (0);
}

int		get_flag(char **f)
{
	int out = 0;

	if (**f == '#')
	{
		out += 1;
		(*f)++;
	}
	if (**f == '-')
	{
		out += 2;
		(*f)++;
	}
	if (**f == '0')
	{
		out += 4;
		(*f)++;
	}
	if (**f == '+')
	{
		out += 8;
		(*f)++;
	}
	return (out);
}

int		get_format(char **f, t_specifier *spec)
{
	if (valid_flag(*f))
		spec->flag = get_flag(f);
	if (valid_field(*f))
		spec->field_width = get_field(f);
	if (valid_width(*f))
	{
		(*f)++;
		spec->max_width = get_width(f);
	}
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

