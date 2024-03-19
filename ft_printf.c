/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:20:42 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/19 11:22:36 by cstoia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_result(const char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*str == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*str == '%')
		count += ft_putchar('%');
	else if (*str == 'd' || *str == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*str == 'u')
		count += ft_put_unsigned_nbr(va_arg(args, unsigned int));
	else if (*str == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putp(va_arg(args, unsigned long));
	}
	else if (*str == 'x')
		count += ft_putx(va_arg(args, unsigned int));
	else if (*str == 'X')
		count += ft_putxxx(va_arg(args, unsigned int));
	else
		count += ft_putchar(*str);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	result;

	result = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(str + 1) == '%')
				result += ft_putchar('%');
			else
				result += ft_result((str + 1), args);
			str++;
		}
		else
			result += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (result);
}
