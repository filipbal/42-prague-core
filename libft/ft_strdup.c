/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:25:57 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/06 18:25:57 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
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

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	if (dest != NULL)
	{
		return (ft_strcpy(dest, src));
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
