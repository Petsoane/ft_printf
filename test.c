/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:54:32 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/09 14:58:34 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int val = 1;

	if (val & 1)
		printf("The first bit is set\n");
	if (val & (1 << 1))
		printf("The second bit is set\n");
	if (val & (1 << 2))
		printf("The third bit is set\n");
	if (val & (1 << 3))
		puts("The fourth bit is set");
	

	return (0);
}
