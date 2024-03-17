/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:55:49 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 16:33:08 by fbalakov         ###   ########.fr       */
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

#include "libft.h"

int	ft_isalpha(int i)
{
	if (('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z'))
		return (1);
	return (0);
}
