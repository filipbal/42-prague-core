/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:39:31 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/15 10:39:31 by fbalakov         ###   ########.fr       */
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
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*castdest;
	const unsigned char	*castsrc;

	castdest = dest;
	castsrc = src;
	i = 0;
	while (i < n)
	{
		castdest[i] = castsrc[i];
		i++;
	}
}
