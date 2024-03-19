/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:23:22 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/19 11:23:15 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbr(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'A');
}

int	ft_putxxx(unsigned int n)
{
	char	a;
	int		count;

	count = 0;
	if (n >= 16)
		count = ft_putxxx(n / 16);
	if (count < 0)
		return (-1);
	n %= 16;
	a = ft_nbr(n);
	if (write(1, &a, 1) < 0)
		return (-1);
	return (count + 1);
}
