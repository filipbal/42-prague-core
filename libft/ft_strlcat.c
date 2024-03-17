/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:48:09 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 16:57:57 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
size_t ft_strlcat(char *dst, const char *src, size_t size);
int	main(void)
{
	char dst[20] = "Filip";
	const char src[] = "Balakovski";
	size_t size = 16; // size of dst & src string + nul char
	printf("Dest before:\n");
	for (int i = 0; i < size; i++)
		printf("%c ", dst[i]);
	printf("\nSource:\n");
	for (int i = 0; i < size; i++)
		printf("%c ", src[i]);
	printf("\nResult of my strlcat: %zu\n", ft_strlcat(dst, src, size));
	printf("Dest after:\n");
	for (int i = 0; i < size; i++)
		printf("%c ", dst[i]);
	printf("\n");
	return (0);
}
*/

// concatenate the src string to the end of the dst string, 
// ensure the total len does not exceed the specified size.

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	while (i < size && dst[i] && !(dst == NULL && size == 0))
		i++;
	j = 0;
	while (src[j] && !(src == NULL && size == 0))
		j++;
	if (size > i)
		res = i + j;
	else
		res = size + j;
	j = 0;
	while (size != 0 && src[j] && (i < size - 1))
		dst[i++] = src[j++];
	if (size > i)
		dst[i] = '\0';
	return (res);
}
