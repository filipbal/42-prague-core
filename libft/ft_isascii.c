/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:50:06 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/12 15:50:06 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
int ft_isascii(int c);
int main(void)
{
	int c = 0x80;
	if (ft_isascii(c) == 1)
		printf("(%c) is ASCII\n", c);
	else
		printf("(%c) is not ASCII\n", c);
	printf("ft_isascii: %i\n", ft_isascii(c));
	printf("isascii: %i\n", isascii(c));
	return (0);
}
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
