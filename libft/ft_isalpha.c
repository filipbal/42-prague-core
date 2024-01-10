/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:55:49 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/10 18:55:49 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
int ft_isalpha(int c);
int main(void)
{
	char c = 'a';
	if (ft_isalpha(c) == 1)
		printf("(%c) is uppercase\n", c);
	else if (ft_isalpha(c) == 2)
		printf("(%c) is lowercase\n", c);
	else
		printf("(%c) is not a letter\n", c);
	printf("ft_isalpha: %i\n", ft_isalpha(c));
	printf("isalpha: %i\n", isalpha(c));
	return (0);
}
*/
int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 95 && c <= 122)
		return (2);
	else
		return (0);
}
