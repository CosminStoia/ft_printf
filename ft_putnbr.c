/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:11:12 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/18 14:38:31 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printnegative(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		count++;
		n = -n;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	char	result;
	int		count;

	count = ft_printnegative(n);
	if (n == 0)
	{
		ft_putchar('0');
		return (count + 1);
	}
	else if (n >= 10)
		count += ft_putnbr(n / 10);
	result = (n % 10) + '0';
	ft_putchar(result);
	count++;
	return (count);
}
