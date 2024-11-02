/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:48:11 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/02 17:11:48 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_put_hex_upper(unsigned int c)
{
	int		run;
	char	*base;
	int		error_check;

	run = 0;
	base = "0123456789ABCDEF";
	if (c >= 16)
	{
		error_check = ft_put_hex_upper(c / 16);
		if (error_check == -1)
			return (-1);
		run += error_check;
		error_check = ft_put_hex_upper(c % 16);
		if (error_check == -1)
			return (-1);
		run += error_check;
	}
	else
	{
		error_check = ft_putchar_pr(base[c % 16]);
		if (error_check == -1)
			return (-1);
		run += error_check;
	}
	return (run);
}

int	ft_put_hex_lower(unsigned long c)
{
	int		run;
	char	*base;
	int		error_check;

	error_check = 0;
	run = 0;
	base = "0123456789abcdef";
	if (c >= 16)
	{
		error_check = ft_put_hex_lower(c / 16);
		if (error_check == -1)
			return (-1);
		run += error_check;
		error_check = ft_put_hex_lower(c % 16);
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

int	ft_put_pointer(unsigned long p)
{
	int		run;
	long	error_check;

	run = 0;
	error_check = ft_putstr_pr("0x");
	if (error_check == -1)
		return (-1);
	run += error_check;
	error_check = ft_put_hex_lower(p);
	if (error_check == -1)
		return (-1);
	run += error_check;
	return (run);
}
