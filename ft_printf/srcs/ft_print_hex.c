/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:11:34 by fbalakov          #+#    #+#             */
/*   Updated: 2024/10/24 10:48:31 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_hex_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_put_hex(unsigned long n, int is_upper)
{
	char	*hex;

	if (is_upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
	{
		ft_put_hex(n / 16, is_upper);
		ft_put_hex(n % 16, is_upper);
	}
	else
		ft_putchar_fd(hex[n], 1);
	return (ft_hex_len(n));
}

int	ft_print_hex(unsigned int n, int is_upper)
{
	return (ft_put_hex(n, is_upper));
}

int	ft_print_ptr(void *ptr)
{
	int				len;
	unsigned long	addr;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	addr = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	len = 2;
	len += ft_put_hex(addr, 0);
	return (len);
}
