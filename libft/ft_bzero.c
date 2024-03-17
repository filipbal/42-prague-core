/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:41:23 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 16:22:22 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <strings.h>
void ft_bzero(void *s, size_t n);
int	main(void)
{
	char s[5] = "AAAA";
	size_t n = 2;

	printf("ft_bzero(%s, %i):\n", s, n);
	ft_bzero(s, n);
	for (int i = 0; i < sizeof(s); i++)	
		printf("%i ", s[i]);
	printf("\n");
	return (0);
}
*/

// ft_bzero sets the first n bytes of the memory area pointed to by s to zero.
// Commonly used for initializing memory buffers or arrays.

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
