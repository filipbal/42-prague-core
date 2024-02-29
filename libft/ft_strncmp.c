/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:40:41 by fbalakov          #+#    #+#             */
/*   Updated: 2024/02/29 21:40:41 by fbalakov         ###   ########.fr       */
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
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	else
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
}
