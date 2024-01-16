/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:07:54 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/15 11:07:54 by fbalakov         ###   ########.fr       */
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
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*castdest;
	const unsigned char	*castsrc;

	castdest = dest;
	castsrc = src;
	i = 0;
	if (castsrc < castdest)
	{
		while (i < n)
		{
			castdest[n - 1 - i] = castsrc[n - 1 - i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			castdest[i] = castsrc[i];
			i++;
			n--;
		}
	}
}
