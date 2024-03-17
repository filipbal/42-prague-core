/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:18:20 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 16:33:30 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
int ft_isdigit(int c);
int main(void)
{
	char c = '0';
	if (ft_isdigit(c) == 1)
		printf("(%c) is a digit\n", c);
	else
		printf("(%c) is NOT a digit\n", c);
	printf("ft_isdigit: %i\n", ft_isdigit(c));
	printf("isdigit: %i\n", isdigit(c));
	return (0);
}
*/

#include "libft.h"

int	ft_isdigit(int i)
{
	while ('0' <= i && i <= '9')
		return (1);
	return (0);
}
