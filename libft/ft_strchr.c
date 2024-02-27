/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:08:01 by fbalakov          #+#    #+#             */
/*   Updated: 2024/02/27 11:08:01 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
char *ft_strchr(const char *s, int c);
int	main(void)
{
	const char s[] = "Filip";
	for (int i = 0; s[i-1] != '\0'; i++)
	{
		printf("%p: %c\n", (void *)&s[i], s[i]);
	}
	int c = 'p';
	char *p = (void *)ft_strchr(s, c);
	if (p == NULL)
		printf("\nCharacter not found.\n");
	else
		printf("\nCharacter '%c' is at address: %p\n", c, p);
	return (0);
}
*/
char *ft_strchr(const char *s, int c)
{
    int i = 0;
    while (s[i-1])
    {
        if (s[i] == c)
            return (char *)&s[i];
        i++;
    }
    return (NULL);
}