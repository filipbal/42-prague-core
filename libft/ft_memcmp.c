/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:13:06 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/06 17:13:06 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
int ft_memcmp(const void *s1, const void *s2, size_t n);
int	main(void)
{
	char s1[] = "Hello";
	char s2[] = "Help";
	size_t n = 4;
	int res = ft_memcmp(s1, s2, n);
	printf("String 1: ");
	for (int i = 0; s1[i] != 0; i++)
		printf("%c", s1[i]);
	printf("\nString 2: ");
	for (int i = 0; s2[i] != 0; i++)
		printf("%c", s2[i]);
	printf("\nResult: %i\n", res);
	if (res == 0)
		printf("First %i bytes are equal.\n", n);
	else if (res > 0)
		printf("String 1 is greater than string 2.\n");
	else
		printf("String 2 is greater than string 1.\n");
	return(0);
}
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
