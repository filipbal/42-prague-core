/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:02:22 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/09 12:24:14 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Count lines in a file
** Handle EOF or error
** Free the line after counting */
int	count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines++;
		free(line);
	}
	close(fd);
	return (lines);
}

/* Create a copy of the map for validation purposes */
char	**map_copy(char **map, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

/* Error handling function */
void	error_exit(char *message, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	cleanup_game(game);
	exit(1);
}
