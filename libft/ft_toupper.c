/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:12:23 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 17:43:47 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
int ft_toupper(int c);
int main(void)
{
	char c = 'a';
	printf("%c\n", ft_toupper(c));
	return (0);
}
*/

// Convert character to uppercase

#include "libft.h"

int	ft_toupper(int i)
{
	if (i > 96 && i < 123)
		i -= 32;
	return (i);
}
