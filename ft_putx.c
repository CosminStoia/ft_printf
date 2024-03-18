/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:38:10 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/18 15:47:14 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'a');
}

int	ft_putx(unsigned int n)
{
	char	a;
	int		count;

	count = 0;
	if (n >= 16)
		count = ft_putx(n / 16);
	if (count < 0)
		return (-1);
	n %= 16;
	a = ft_nbr(n);
	if (write(1, &a, 1) < 0)
		return (-1);
	return (count + 1);
}
