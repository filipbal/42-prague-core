/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:16:47 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/17 08:16:47 by fbalakov         ###   ########.fr       */
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
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!(size > 0))
		return (0);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
