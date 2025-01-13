/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:21:37 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 11:53:43 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Validates if a string represents a valid integer format
** @param str: String to validate
** @return: 1 if valid integer format, 0 if invalid
*/
int	is_valid_integer(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*
** Converts string to long integer with strict validation
** @param str: String to convert
** @return: Converted long integer value
** Note: Assumes input has been validated by is_valid_integer
*/
long	ft_atoi_strict(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
** Checks if a string represents a number within INT range
** @param str: String to check
** @return: 1 if within INT range, 0 if outside
*/
int	is_within_limits(char *str)
{
	long	num;

	num = ft_atoi_strict(str);
	return (num >= INT_MIN && num <= INT_MAX);
}
