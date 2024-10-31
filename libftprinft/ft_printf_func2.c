/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:48:11 by poverbec          #+#    #+#             */
/*   Updated: 2024/10/31 14:53:55 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_put_hex_upper(unsigned int c)
{
	int		run;
	char	*base;

	run = 0;
	base = "0123456789ABCDEF";
	if (c >= 16)
	{
		run += ft_put_hex_upper(c / 16);
		run += ft_put_hex_upper(c % 16);
	}
	else
		run += ft_putchar_pr(base[c % 16]);
	return (run);
}
