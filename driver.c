/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 07:52:10 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/12 13:00:59 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	/* Dont forget to fix the workings of the float conversion. */
	ft_printf(" %0100.10s  %.10f specifer, and the number is: %100x|\n","Hello the first ",10.999, 100);
	return (0);
}
