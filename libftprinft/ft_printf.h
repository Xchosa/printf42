/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:06:07 by poverbec          #+#    #+#             */
/*   Updated: 2024/10/31 14:55:47 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr_pr(int n);
int	ft_putchar_pr(char c);

int	ft_putstr_pr(char *s);
int	ft_put_unsig_int(unsigned int n);
int	ft_put_hex_lower(unsigned int c);
int	ft_put_hex_upper(unsigned int c);

int	ft_parse(va_list args, char c);

#endif