/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:38:19 by fbalakov          #+#    #+#             */
/*   Updated: 2024/12/12 09:56:16 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_handle_str(va_list args)
{
	char	*str;
	int		result;

	result = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	while (str[result])
		result++;
	return (result);
}

static int	count_digits(int n)
{
	int	result;

	result = 0;
	if (n <= 0)
		result = 1;
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static int	ft_handle_num(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
	return (count_digits(num));
}

static int	ft_handle_format(char format, va_list args)
{
	if (format == 's')
		return (ft_handle_str(args));
	else if (format == 'd')
		return (ft_handle_num(args));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += ft_handle_format(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
