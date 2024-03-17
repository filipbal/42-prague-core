/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:16:47 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 18:25:44 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
size_t ft_strlcpy(char *dst, const char *src, size_t size);
int	main(void)
{
	char dst[10];
	const char src[] = "Bali";
	size_t size = 5; // size of src string + nul char
	printf("Dest before:\n");
	for (int i = 0; i < size; i++)
		printf("%c ", dst[i]);
	printf("\nSource:\n");
	for (int i = 0; i < size; i++)
		printf("%c ", src[i]);
	printf("\nResult of my strlcpy: %zu\n", ft_strlcpy(dst, src, size));
	printf("Dest after:\n");
	for (int i = 0; i < size; i++)
		printf("%c ", dst[i]);
	printf("\n");
	return (0);
}
*/

// copy characters from the source string to the dst string
// ensure the total len does not exceed the specified size.

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
