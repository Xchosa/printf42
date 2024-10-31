/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:19:17 by poverbec          #+#    #+#             */
/*   Updated: 2024/10/30 18:37:33 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"


int ft_printf(const char *format, ...)
{
	va_list	args;
	int run;

	run = 0; 
	va_start(args, format);

	while (*format)
	{
		if (format[run++] == '%') 
		{
			if (format[run]== '%')
				ft_putchar_pr(va_arg(args, int));
			ft_parse(args, format[run]);
		}
		else 
			putchar(*format);
		format++;
	}
	
va_end(args);
return (0);
}

int ft_parse(va_list args, char c)
{
	if(c == 'c' || c == 'i')
		ft_putchar_pr(va_arg(args, int));
	else if(c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if(c == 'u') // unsigned dez
		
	else if(c == 'x')// hexa lower
		
	else if(c == 's') // null terminated string
		ft_putstr_pr(c)
	else if(c == 'X')// hexa upper
		ft_put_hex_lower(int);
	else if (c == 'p')// pointer
	{
		run = "Ox"
	}
}

#include <stdio.h>

int main()
{
	int result = printf("custom: %s, %d, %c, %x\n", "characters", 123, 'A', 255);
	ft_printf("custom: %s, %d, %c, %x\n", "characters", 123, 'A', 255);
	return 0;
}