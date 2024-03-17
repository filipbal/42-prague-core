/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:30:40 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 16:55:51 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
char *ft_strjoin(char const *s1, char const *s2);
int	main(void)
{
	char const s1[] = "Mi";
	char const s2[] = "ska";
	char *result = ft_strjoin(s1, s2);
	if (result != NULL)
		printf("Concatenated string: %s\n", result);
	free(result); // Free the memory allocated by ft_strjoin
	return 0;
}
*/

// allocates with malloc and returns a new string by concatenation
// s1 prefix and s2 suffix string

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	l1 = 0;
	while (s1[l1])
		l1++;
	l2 = 0;
	while (s2[l2])
		l2++;
	str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < l1)
		str[i] = s1[i];
	i = -1;
	while (++i < l2)
		str[l1 + i] = s2[i];
	str[l1 + l2] = '\0';
	return (str);
}
