/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:59:54 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/06/05 15:58:57 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//static void	get_spectype(const char *f);

void		ft_printf(const char *f, ...)
{
	int			arg_count;
	//va_list		args;
	
	arg_count = count_arg(f);

	if (arg_count < 0)
	{
		ft_putstr_fd("Error with the speciifers\n", 2);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", arg_count);
	ft_putstr(f);
}
