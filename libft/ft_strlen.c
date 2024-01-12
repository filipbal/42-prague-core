/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:37:55 by fbalakov          #+#    #+#             */
/*   Updated: 2024/01/12 16:37:55 by fbalakov         ###   ########.fr       */
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
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
