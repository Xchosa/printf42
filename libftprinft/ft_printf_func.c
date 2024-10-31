/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:47:02 by poverbec          #+#    #+#             */
/*   Updated: 2024/10/30 18:46:08 by poverbec         ###   ########.fr       */
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

	run = 0;
	if (s == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (s[run] != '\0')
	{
		ft_putchar_pr(s[run]);
		run++;
	}
	return (run);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	number;
	char	c;

	number = n;
	if (number < 0)
	{
		c = '-';
		write(fd, &c, 1);
		number = -number;
	}
	if (number >= 10)
	{
		ft_putnbr_fd(number / 10, fd);
	}
	c = (number % 10) + '0';
	write(fd, &c, 1);
}
int	ft_put_hex_lower(unsigned int c)
{
	int run;
	char *base;

	run = 0;
	base ="0123456789abcdef";
	if(c >= 16)
	{
		run += ft_put_hex_lower(c / 16);
		run += ft_put_hex_lower(c %16);
	}
	else
		run += putchar(base[c % 16]);
	return (run);
}
 