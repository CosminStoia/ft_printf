/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:38:10 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/16 13:40:45 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putx(unsigned int n)
{
	int i;
	char buffer[11];
	char *hex_digits;

	i = 0;

	if (n == 0)
	{
		ft_putc('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = n % 10 + '0';
		n = n / 10;
	}
	while (i > 0)
	{
		ft_putc(buffer[i]);
		i--;
	}
	return (1);
}