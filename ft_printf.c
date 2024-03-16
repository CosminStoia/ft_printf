/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:20:42 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/16 18:29:16 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (str == 'c')
			{
                ft_putchar();
			}
			else if (str == 's')
			{
			}
			else if (str == 'p')
			{
                ft_putstr("0x");
			}
			else if (str == 'd' || str == 'i')
			{
                ft_putnbr();
			}
			else if (str == 'u')
			{
                ft_put_unsigned_nbr();
			}
			else if (str == 'x' || str == 'X')
			{
			}
			else if (str == '%')
			{
			}
			else
			{
			}
		}
	}

	va_end(args);
}
