/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:04:27 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 16:33:04 by fbalakov         ###   ########.fr       */
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

#include "libft.h"

int	ft_isalnum(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')
		|| (i >= '0' && i <= '9'))
		return (1);
	return (0);
}
