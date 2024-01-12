/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:30:27 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/12 16:30:27 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
int ft_isprint(int c);
int main(void)
{
	int c = 'a';
	if (ft_isprint(c) == 1)
		printf("(%c) is a printable character from ASCII table\n", c);
	else
		printf("(%c) is NOT a printable character from ASCII table\n", c);
	printf("ft_isprint: %i\n", ft_isprint(c));
	printf("isprint: %i\n", isprint(c));
	return (0);
}
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
