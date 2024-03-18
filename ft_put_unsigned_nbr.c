/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:18:00 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/18 17:49:37 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr(unsigned int n)
{
	char	result;
	int		count;

	count = 0;
	if ((n / 10) != 0)
	{
		count += ft_put_unsigned_nbr(n / 10);
	}
	result = (n % 10) + '0';
	ft_putchar(result);
	count++;
	return (count);
}
