/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:40:20 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/04 19:40:20 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
void *memchr(const void s[.n], int c, size_t n);
int	main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	ft_memchr(s, 0, 0);
	ft_memchr(s, 2, 3);
	return(0);
}
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*string;

	if (s == NULL)
		return (NULL);
	i = 0;
	string = (void *)s;
	while (i < n)
	{
		if (string[i] == (char)c)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
