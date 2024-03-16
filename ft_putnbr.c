/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:11:12 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/16 18:24:25 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	putnbr(int n)
{
	char	result;

	if (n == -2147483648)
	{
		ft_putchar('-');
		putnbr(2);
		putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		putnbr(-n);
	}
	else if (n == 0)
	{
		ft_putchar('0');
	}
	else if (n >= 10)
	{
		putnbr(n / 10);
		result = (n % 10) + '0';
		ft_putchar(result);
	}
	return (0);
}

int	ft_putnbr(int n)
{
	if (putnbr(n) < 0)
		return (-1);
	return (1);
}
