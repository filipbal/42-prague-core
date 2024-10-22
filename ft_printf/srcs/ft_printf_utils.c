/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:03:57 by fbalakov          #+#    #+#             */
/*   Updated: 2024/10/22 10:00:17 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	if (write(1, "0x", 2) == -1)
		return (-1);
	count = 2;
	count += ft_put_hex((unsigned long)ptr, 0);
	if (count < 2)
		return (-1);
	return (count);
}

int	ft_print_int(int n)
{
	char	*num;
	int		len;

	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = ft_print_str(num);
	free(num);
	return (len);
}

int	ft_print_uint(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
	{
		count = ft_print_uint(n / 10);
		if (count == -1)
			return (-1);
	}
	c = n % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_print_hex(unsigned int n, int is_upper)
{
	return (ft_put_hex(n, is_upper));
}

int	ft_put_hex(unsigned long n, int is_upper)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 16)
	{
		count = ft_put_hex(n / 16, is_upper);
		if (count == -1)
			return (-1);
	}
	if (n % 16 < 10)
		c = n % 16 + '0';
	else if (is_upper)
		c = n % 16 - 10 + 'A';
	else
		c = n % 16 - 10 + 'a';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}
