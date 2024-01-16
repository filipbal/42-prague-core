/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:47:36 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/12 16:47:36 by fbalakov         ###   ########.fr       */
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
void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}
