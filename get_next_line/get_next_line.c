/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:39:07 by fbalakov          #+#    #+#             */
/*   Updated: 2024/10/25 13:46:20 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

static char	*get_remaining(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (ft_free(stash));
	i++;
	if (!stash[i])
		return (ft_free(stash));
	new_stash = malloc(ft_strlen_gnl(&stash[i]) + 1);
	if (!new_stash)
		return (ft_free(stash));
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

static char	*get_current_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(stash));
	stash = read_and_append(fd, stash, buffer);
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
			stash = ft_free(stash);
		return (NULL);
	}
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	if (!stash[0])
	{
		stash = ft_free(stash);
		return (NULL);
	}
	line = get_current_line(stash);
	if (!line)
	{
		stash = ft_free(stash);
		return (NULL);
	}
	stash = get_remaining(stash);
	return (line);
}
