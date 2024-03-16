/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:31:53 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/16 18:00:07 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	hex_convert(unsigned long n)
{
	int	i;
	int	reminder;
	int	result;

	i = 1;
	while (n > 0)
	{
		reminder = n % 16;
		if (reminder < 10)
			result += reminder * i;
		else
			result += (reminder - 10 + 'A') * i;
		n = n / 16;
		i *= 10;
	}
	return (result);
}
