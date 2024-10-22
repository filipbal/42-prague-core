/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:38:19 by fbalakov          #+#    #+#             */
/*   Updated: 2024/10/22 09:56:16 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char format, va_list args)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = ft_print_char(va_arg(args, int));
	else if (format == 's')
		result = ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		result = ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		result = ft_print_int(va_arg(args, int));
	else if (format == 'u')
		result = ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x')
		result = ft_print_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		result = ft_print_hex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		result = ft_print_percent();
	return (result);
}

static int	ft_process_format(const char **format, va_list args, int *count)
{
	int	tmp;

	(*format)++;
	tmp = ft_handle_format(**format, args);
	if (tmp == -1)
		return (-1);
	*count += tmp;
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
		if (*format == '%')
		{
			if (ft_process_format(&format, args, &count) == -1)
				return (-1);
		}
		else if (write(1, format, 1) == -1)
			return (-1);
		else
			count++;
		format++;
	}
	va_end(args);
	return (count);
}
