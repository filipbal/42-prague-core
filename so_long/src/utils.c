/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:02:22 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/09 11:40:28 by fbalakov         ###   ########.fr       */
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

/* Get screen dimensions and validate window size */
int	get_window_size(t_game *game, int *width, int *height)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	*width = game->map_width * TILE_SIZE;
	*height = game->map_height * TILE_SIZE;
	if (*width > screen_width || *height > screen_height)
	{
		ft_printf("Error\nMap is too large for screen resolution (%dx%d)\n",
			screen_width, screen_height);
		return (0);
	}
	return (1);
}

/* Print game statistics */
void	print_game_stats(t_game *game)
{
	ft_printf("\nGame Statistics:\n");
	ft_printf("Map size: %dx%d\n", game->map_width, game->map_height);
	ft_printf("Collectibles: %d\n", game->collectibles);
	ft_printf("Moves made: %d\n", game->moves);
}

/* Debug function to print current map state */
void	debug_print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
}
