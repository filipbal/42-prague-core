/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:40:41 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 18:24:46 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int	main(void)
{
	char			s1[100];
	char			s2[100];
	unsigned int	n;
	int				r;

	printf("Enter string 1: \n");
	scanf("%s", s1);
	printf("Enter string 2: \n");
	scanf("%s", s2);
	printf("Enter first n bytes to compare: \n");
	scanf("%i", &n);
	r = ft_strncmp(s1, s2, n);
	if (r == 0)
	{
		printf("%s and %s are equal in first %i bytes (%i)\n", s1, s2, n, r);
	}
	else if (r < 0)
	{
		printf("%s is less than %s in first %i bytes (%i)\n", s1, s2, n, r);
	}
	else
	{
		printf("%s is greater than %s in first %i bytes (%i)\n", s1, s2, n, r);
	}
	return (0);
}
*/

// Compare the first n characters of the strings s1 and s2
// up to a specified length.

#include "libft.h"

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
