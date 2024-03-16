/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:18:00 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/16 18:24:42 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	put_unsigned_nbr(int n)
{
	char	result;

	ft_putnbr(n / 10);
	result = (n % 10) + '0';
	ft_putchar(result);
}

int	ft_put_unsigned_nbr(int n)
{
	if (put_unsigned_nbr(n) < 0)
		return (-1);
	return (1);
}
