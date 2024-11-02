/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:19:17 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/02 17:08:43 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		run;
	int		error_check;

	run = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			error_check = ft_parse(args, *format);
			if (error_check == -1)
				return (va_end(args), -1);
		}
		else
		{
			error_check = ft_putchar_pr(*format);
			if (error_check == -1)
				return (-1);
		}
		run += error_check;
		format++;
	}
	return (va_end(args), run);
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
		run = ft_put_hex_lower_int(va_arg(args, unsigned int));
	else if (c == 's')
		run += ft_putstr_pr(va_arg(args, char *));
	else if (c == 'X')
		run = ft_put_hex_upper(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		run = ft_put_pointer(va_arg(args, unsigned long));
	}
	else if (c == '%')
		run = ft_putchar_pr('%');
	return (run);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*d;
// 	int		result;

// 	d = "hello";
// 	result = printf("custom: %s, %d, %u, %c, %x, %X, %p\n", "characters", 123,
// 			-5, 'A', 255, 565, d);
// 	ft_printf("custom: %s, %d, %u, %c, %x, %X, %p\n", "characters", 123, -5,
// 			'A', 255, 565, d);
// 	return (0);
// }
