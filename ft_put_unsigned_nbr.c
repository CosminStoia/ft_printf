/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:18:00 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/18 15:46:54 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_unsigned_nbr(int n)
{
	int		count;
	char	result;

	count = 0;
	if (n == 0)
		return (0);
	count += put_unsigned_nbr(n / 10);
	result = (n % 10) + '0';
	ft_putchar(result);
	count++;
	return (count);
}

int	ft_put_unsigned_nbr(int n)
{
	if (put_unsigned_nbr(n) < 0)
		return (-1);
	return (put_unsigned_nbr(n));
}
