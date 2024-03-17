/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:19:50 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 16:24:35 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_atoi() function converts the initial portion of the string to int.
// ft_atoi() function returns the converted value or 0 on error.

#include "libft.h"

int	ft_atoi(char *str)
{
	int		i;
	int		num;
	int		sign;

	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	while ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '+')
			i++;
		else
		{
			sign *= -1;
			i++;
		}
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (sign * num);
}
