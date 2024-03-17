/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:29:08 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 17:05:23 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
char *ft_strnstr(const char *big, const char *little, size_t len);
int main(void)
{
	const char big[] = "Michaela";
	const char little[] = "cha";
	size_t len = 9;
	char *res = ft_strnstr(big, little, len);
	return (0);
}
*/

// If little is an empty string, big is returned; if little	occurs nowhere
// in big, NULL is returned; otherwise a pointer to	the first character of
// the first occurrence of little is returned.

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	if (!*little)
		return ((char *)big);
	b = 0;
	while (big[b] && b < len)
	{
		l = 0;
		while (big[b + l] == little[l] && little[l] && b + l < len)
			l++;
		if (!little[l])
			return ((char *)&big[b]);
		b++;
	}
	return (NULL);
}
