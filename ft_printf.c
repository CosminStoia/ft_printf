/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:20:42 by cstoia            #+#    #+#             */
/*   Updated: 2024/03/18 15:46:48 by cstoia           ###   ########.fr       */
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
		ft_putstr("0x");
		count += ft_putp(va_arg(args, unsigned int));
	}
	else if (*str == 'x')
		count += ft_putx(va_arg(args, unsigned int));
	else if (*str == 'X')
		count += ft_putxx(va_arg(args, unsigned int));
	else
		count += ft_putchar(*str);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count = ft_result(str, args);
		}
		else
		{
			ft_putchar(*str);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int				len;
// 	int				len2;
// 	unsigned int	ui;
// 	void			*addr;

// 	len = ft_printf("Let`s try to print a simple sentence.\n");
// 	len2 = printf("Let`s try to print a simple sentence.\n");
// 	ui = (unsigned int)2147483647 + 1024;
// 	addr = (void *)0x7ffe637541f0;
// 	ft_printf("Lenght: %d, %i\n", len, len);
// 	printf("Lenght: %d, %i\n", len, len);
// 	ft_printf("Negative: %d\n", -762534);
// 	printf("Negative: %d\n", -762534);
// 	ft_printf("Unsigned: %u\n", ui);
// 	printf("Unsigned: %u\n", ui);
// 	ft_printf("Unsigned hexadecimal: %x, %X\n", ui, ui);
// 	printf("Unsigned hexadecimal: %x, %X\n", ui, ui);
// 	ft_printf("Charachter: %c\n", 'H');
// 	printf("Charachter: %c\n", 'H');
// 	ft_printf("String: %s\n", "I am a string!");
// 	printf("String: %s\n", "I am a string!");
// 	ft_printf("Adress: %p\n", addr);
// 	printf("Adress: %p\n", addr);
// 	len = ft_printf("Percent: %%\n");
// 	len2 = printf("Percent: %%\n");
// 	ft_printf("Len: %d\n", len);
// 	printf("Len: %d\n", len2);
// }
