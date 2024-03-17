/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:39:31 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 17:41:33 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
void *ft_memcpy(void *dest, const void *src, size_t n);
int	main(void)
{
	char dest[5];
	char src[5] = "aaaa";
	size_t n = 2;
	printf("Src:\n");
	for (int i = 0; i < sizeof(src); i++)
		printf("%i ", src[i]);
	printf("\n");
	printf("Dest before:\n");
	for (int i = 0; i < sizeof(dest); i++)
		printf("%i ", dest[i]);
	printf("\n");

	ft_memcpy(dest, src, n);

	printf("Dest after:\n");
	for (int i = 0; i < sizeof(dest); i++)
		printf("%i ", dest[i]);
	printf("\n");
	return (0);
}
*/

// ft_memcpy is copies n bytes from the memory area pointed to by src
// to the memory area pointed to by dest.
// It performs a byte-wise copy.

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
