/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:37:55 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 17:02:16 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
size_t ft_strlen(const char *s);
int main(void)
{
	char s[] = "Filip";
	printf("ft_strlen(): %i\n", ft_strlen(s));
	printf("strlen(): %i\n", strlen(s));
	return (0);
}
*/

// Calculate the length of a string without NUL-terminator.

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
