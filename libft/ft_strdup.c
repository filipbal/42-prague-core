/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:25:57 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 17:26:31 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *src = "Source";
    
    // Duplicate a string
    char *duplicate = ft_strdup(src);
    if (duplicate != NULL)
    {
        printf("Original string address: %p\n", (void*)src);
        printf("Duplicated string address: %p\n", (void*)duplicate);
        free(duplicate); // Free the allocated memory when done
    }
    else
    {
        printf("Memory allocation failed\n");
    }

    return 0;
}
// strdup() returns a pointer to a new string which is a duplicate of string s
// memory for new string is obtained with malloc() and can be freed with free()
// on success, the strdup() function returns a pointer to the duplicated string
// it returns NULL if insufficient memory was available, with err number set
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
