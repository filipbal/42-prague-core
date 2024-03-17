/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:08:01 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 18:32:33 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
char *ft_strchr(const char *s, int c);
int	main(void)
{
	const char s[] = "Filip";
	for (int i = 0; s[i] >= '\0'; i++)
	{
		printf("%p: %c\n", (void *)&s[i], s[i]);
	}
	int c = 'i';
	char *p = (void *)ft_strchr(s, c);
	if (p == NULL)
		printf("\nCharacter not found.\n");
	else
		printf("\nCharacter '%c' is at address: %p\n", c, p);
	return (0);
}
*/

// ft_strchr searches for the first occurrence
// of a character c in the input string s.

#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}
