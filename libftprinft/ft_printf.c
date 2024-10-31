/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:19:17 by poverbec          #+#    #+#             */
/*   Updated: 2024/10/31 17:38:31 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		run;
	int		counter;

	run = 0;
	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			run += ft_parse(args, *format);
			format++;
		}
		else
		{
			run += ft_putchar_pr(*format);
			format++;
		}
	}
	va_end(args);
	return (run);
}

int	ft_parse(va_list args, char c)
{
	int	run;

	run = 0;
	if (c == 'd' || c == 'i')
		run = ft_putnbr_pr(va_arg(args, int));
	else if (c == 'u')
		run = ft_put_unsig_int(va_arg(args, unsigned int));
	else if (c == 'c')
		run = ft_putchar_pr(va_arg(args, int));
	else if (c == 'x')
		run = ft_put_hex_lower(va_arg(args, unsigned int));
	else if (c == 's')
		run += ft_putstr_pr(va_arg(args, char *));
	else if (c == 'X')
		run = ft_put_hex_upper(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		run += ft_putstr_pr("0x");
		run += ft_put_hex_lower((unsigned long)(va_arg(args, void *)));
	}
	else if (c == '%')
		run = ft_putchar_pr('%');
	return (run);
}

#include <stdio.h>

int	main(void)
{
	char *d;

	d = "hello";
	int result = printf("custom: %s, %d, %c, %x, %p\n", "characters", 123, 'A',
			255, d);
	ft_printf("custom: %s, %d, %c, %x , %p\n", "characters", 123, 'A', 255, d);
	return (0);
}
