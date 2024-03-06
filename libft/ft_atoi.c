/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:19:50 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/06 18:19:50 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	// Check arguments
	if (argc != 2)
	{
		printf("Usage: ./ft_atoi number\n");
		return 1; // EXIT 1
	}
	
	// Convert argument string to integer
	printf("FT_ATOI: %i\n", ft_atoi(argv[1]));
	printf("ATOI: %i\n", atoi(argv[1]));

	return (0);
}
*/

// The atoi() function converts the initial portion of the string to int.
// The atoi() function returns the converted value or 0 on error.

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
