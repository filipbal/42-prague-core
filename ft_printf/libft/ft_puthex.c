/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:37:25 by fbalakov          #+#    #+#             */
/*   Updated: 2024/10/06 19:37:25 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_puthex(unsigned long num, int uppercase)
{
    char *hex;
    if (uppercase)
        hex = "0123456789ABCDEF";
    else
        hex = "0123456789abcdef";
    
    if (num >= 16)
        ft_puthex(num / 16, uppercase);
    ft_putchar_fd(hex[num % 16], 1);
}