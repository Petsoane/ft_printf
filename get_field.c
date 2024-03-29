/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:21:41 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/09 13:10:32 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_field(char **f)
{
	static char out[1000];
	int i;

	i = 0;
	while (**f >= '0' && **f <= '9')
	{
		out[i++] = **f;
		(*f)++;
	}
	out[i] = '\0';
	return (out);
}
