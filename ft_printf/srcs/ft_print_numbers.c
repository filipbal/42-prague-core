/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:11:37 by fbalakov          #+#    #+#             */
/*   Updated: 2024/10/25 09:14:24 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_count_digits(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_count_uint_digits(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_put_uint_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_put_uint_fd(n / 10, fd);
		ft_put_uint_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int	ft_print_int(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_count_digits(n));
}

int	ft_print_uint(unsigned int n)
{
	ft_put_uint_fd(n, 1);
	return (ft_count_uint_digits(n));
}
