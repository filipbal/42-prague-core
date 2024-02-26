/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:39:20 by fbalakov          #+#    #+#             */
/*   Updated: 2024/02/26 20:39:20 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
int ft_tolower(int c);
int main(void)
{
	char c = 'Z';
	printf("%c\n", ft_tolower(c));
	return (0);
}
*/
int	ft_tolower(int c)
{
	if (c > 64 && c < 97)
		c += 32;
	return (c);
}
