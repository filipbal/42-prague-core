/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:07:54 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 17:41:03 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
void *ft_memmove(void *dest, const void *src, size_t n);
int	main(void)
{
	char dest[20] = "Destination";
	char src[20] = "Source";
	size_t n = 2;
	printf("Src:\n");
	for (int i = 0; i < sizeof(src); i++)
		printf("%c ", src[i]);
	printf("\n");
	printf("Dest before:\n");
	for (int i = 0; i < sizeof(dest); i++)
		printf("%c ", dest[i]);
	printf("\n");
	ft_memmove(dest, src, n);
	printf("Dest after:\n");
	for (int i = 0; i < sizeof(dest); i++)
		printf("%c ", dest[i]);
	printf("\n");
	return (0);
}
*/

// Unlike memcpy, memmove handles overlapping memory areas correctly.
// It ensures that the data is correctly copied
// even if the src and dest regions overlap.

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	len;

	len = 0;
	if (s2 < s1)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)s1)[len] = ((unsigned char *)s2)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)s1)[len] = ((unsigned char *)s2)[len];
			len++;
		}
	}
	return (s1);
}
