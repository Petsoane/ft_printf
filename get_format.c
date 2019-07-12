/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:47:10 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/12 12:50:32 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
