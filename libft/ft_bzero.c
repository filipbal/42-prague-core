/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:41:23 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/15 09:41:23 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <strings.h>
void ft_bzero(void *s, size_t n);
int	main(void)
{
	char s[5] = "AAAA";
	size_t n = 2;

	printf("ft_bzero(%s, %i):\n", s, n);
	ft_bzero(s, n);
	for (int i = 0; i < sizeof(s); i++)	
		printf("%i ", s[i]);
	printf("\n");
	return (0);
}
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
