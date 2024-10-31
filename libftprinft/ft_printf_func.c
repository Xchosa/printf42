/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:47:02 by poverbec          #+#    #+#             */
/*   Updated: 2024/10/31 17:11:56 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putchar_pr(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_pr(char *s)
{
	int	run;
	int	error_check;

	run = 0;
	if (s == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (*s != '\0')
	{
		error_check = ft_putchar_pr(*s++);
		if (error_check == -1)
			return (-1);
		run += error_check;
	}
	return (run);
}

int	ft_putnbr_pr(int n)
{
	long	number;
	char	c;
	int		run;
	int		error_check;

	number = n;
	run = 0;
	if (number < 0)
	{
		run += ft_putchar_pr('-');
		number = -number;
	}
	if (number >= 10)
	{
		error_check = run;
		if (error_check == -1)
			return (-1);
		run += ft_putnbr_pr(number / 10);
	}
	c = (number % 10) + '0';
	run += (ft_putchar_pr(c));
	return (run);
}

int	ft_put_unsig_int(unsigned int n)
{
	unsigned int	run;

	run = 0;
	if (n >= 10)
	{
		run += ft_put_unsig_int(n / 10);
	}
	run += (ft_putchar_pr(n % 10) + '0');
	return (run);
}

int	ft_put_hex_lower(unsigned int c)
{
	int		run;
	char	*base;

	run = 0;
	base = "0123456789abcdef";
	if (c >= 16)
	{
		run += ft_put_hex_lower(c / 16);
		run += ft_put_hex_lower(c % 16);
	}
	else
		run += ft_putchar_pr(base[c]);
	return (run);
}
