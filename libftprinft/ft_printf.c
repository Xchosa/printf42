/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:19:17 by poverbec          #+#    #+#             */
/*   Updated: 2024/10/31 14:31:33 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		run;

	run = 0;
	va_start(args, format);
	while (*format)
	{
		if (format[run++] == '%')
		{
			if (format[run] == '%')
				ft_putchar_pr(va_arg(args, int));
			ft_parse(args, format[run]);
		}
		else
			ft_putchar_pr(*format);
		format++;
	}
	va_end(args);
	return (0);
}

int	ft_parse(va_list args, char c)
{
	int	run;

	run = 0;
	if (c == 'd' || c == 'i')
		run = ft_putchar_pr(va_arg(args, int));
	else if (c == 'd')
		run = ft_putnbr_pr(va_arg(args, int));
	else if (c == 'u')
		run = ft_put_unsig_int(va_arg(args, int));
	else if (c == 'c')
		run = ft_putchar_pr(va_arg(args, int));
	else if (c == 'x')
		run = ft_put_hex_lower(va_arg(args, int));
	else if (c == 's')
		run = ft_putstr_pr(va_arg(args, char *));
	else if (c == 'X')
		run = ft_put_hex_upper(va_arg(args, int));
	else if (c == 'p')
	{
		run = ft_putstr_pr("Ox");
		run = ft_put_hex_lower(va_arg(args, unsigned int));
	}
	else if (c == '%')
		run = ft_putchar_pr('%');
	return (run);
}

// #include <stdio.h>

// int main()
// {
// 	int result = printf("custom: %s, %d, %c, %x\n", "characters", 123, 'A',
//			255);
// 	ft_printf("custom: %s, %d, %c, %x\n", "characters", 123, 'A', 255);
// 	return (0);
// }