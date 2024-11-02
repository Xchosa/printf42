/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:47:02 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/02 17:08:00 by poverbec         ###   ########.fr       */
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
	int		run;
	int		error_check;

	number = n;
	run = 0;
	if (number < 0)
	{
		error_check = ft_putchar_pr('-');
		if (error_check == -1)
			return (-1);
		run += error_check;
		number = -number;
	}
	if (number >= 10)
	{
		error_check = ft_putnbr_pr(number / 10);
		if (error_check == -1)
			return (-1);
		run += error_check;
	}
	error_check = (ft_putchar_pr((number % 10) + '0'));
	if (error_check == -1)
		return (-1);
	return (run += error_check, run);
}

int	ft_put_unsig_int(unsigned int n)
{
	int				run;
	unsigned int	number;
	char			c;
	int				error_check;

	run = 0;
	number = n;
	if (number >= 10)
	{
		error_check = ft_put_unsig_int(number / 10);
		if (error_check == -1)
			return (-1);
		run += error_check;
	}
	c = ((number % 10) + '0');
	error_check = ft_putchar_pr(c);
	if (error_check == -1)
		return (-1);
	run += error_check;
	return (run);
}

int	ft_put_hex_lower_int(unsigned int c)
{
	int		run;
	char	*base;
	int		error_check;

	error_check = 0;
	run = 0;
	base = "0123456789abcdef";
	if (c >= 16)
	{
		error_check = ft_put_hex_lower_int(c / 16);
		if (error_check == -1)
			return (-1);
		run += error_check;
		error_check = ft_put_hex_lower_int(c % 16);
		if (error_check == -1)
			return (-1);
	}
	else
	{
		error_check = ft_putchar_pr(base[c]);
		if (error_check == -1)
			return (-1);
	}
	run += error_check;
	return (run);
}
