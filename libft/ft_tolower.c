/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:39:20 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 17:44:11 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
int ft_tolower(int c);
int main(void)
{
	char c = 'Z';
	printf("%c\n", ft_tolower(c));
	return (0);
}
*/

// Convert character to lowercase

#include "libft.h"

int	ft_tolower(int i)
{
	if (i > 64 && i < 97)
		i += 32;
	return (i);
}
