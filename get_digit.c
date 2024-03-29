/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:13:16 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/05 19:16:25 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_width(char **f)
{
	static char		out[10000];
	int i;

	i = 0;
	while (ft_isdigit(**f))
	{
		out[i++] = **f;
		(*f)++;
	}
	out[i] = '\0';
	return (out);
}
