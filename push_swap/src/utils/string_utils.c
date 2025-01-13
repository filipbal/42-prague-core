/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:15:10 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 22:02:32 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str)
{
	int	count;
	int	i;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	word_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i + len] && str[i + len] != ' ')
		len++;
	return (len);
}

char	*get_next_word(char *str, int *i)
{
	char	*word;
	int		len;
	int		j;

	while (str[*i] == ' ')
		(*i)++;
	len = word_len(str, *i);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
		word[j++] = str[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**words;
	int		i;
	int		word_count;
	int		w;

	if (!str)
		return (NULL);
	word_count = count_words(str);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	i = 0;
	w = 0;
	while (w < word_count)
	{
		words[w] = get_next_word(str, &i);
		if (!words[w])
		{
			free_split(words);
			return (NULL);
		}
		w++;
	}
	words[w] = NULL;
	return (words);
}
