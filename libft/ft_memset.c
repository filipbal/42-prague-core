/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:47:36 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 17:42:44 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
void *ft_memset(void *s, int c, size_t n);
int	main(void)
{
	char str[11] = {0};
	ft_memset(str, 'A', sizeof(char) * 5);
	memset(str + 5, 'B', sizeof(char) * 5);
	printf("memset: %s\n", str);
	return (0);
}
*/

// Set first n bytes of the memory pointed to by s to the value of c.
// It initializes a block of memory with a specific value.

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}
