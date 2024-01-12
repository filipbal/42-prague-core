/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:04:27 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/12 15:04:27 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
int ft_isalnum(int c);
int main(void)
{
	char c = '.';
	if (ft_isalnum(c) == 1)
		printf("(%c) is alphanumeric\n", c);
	else
		printf("(%c) is NOT alphanumeric\n", c);
	printf("ft_isalnum: %i\n", ft_isalnum(c));
	printf("isalnum: %i\n", isalnum(c));
	return (0);
}
*/
int	ft_isalpha(int c);
int	ft_isdigit(int c);

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 95 && c <= 122)
		return (2);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0 || ft_isdigit(c) != 0)
		return (1);
	else
		return (0);
}
