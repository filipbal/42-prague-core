/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:54:28 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/09 11:13:37 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Takes a game struct and filename, reads map dimensions
** Validates each line length is consistent
** Returns 1 if dimensions are valid, 0 on error */
static int	get_map_dimensions(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	game->map_height = 0;
	game->map_width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			len--;
		if (game->map_height == 0)
			game->map_width = len;
		else if ((int)len != game->map_width)
			return (free(line), close(fd), 0);
		free(line);
		game->map_height++;
	}
	return (close(fd), (game->map_height > 0 && game->map_width > 0));
}

/* Allocates memory for map and reads content from file
** Strips newlines and copies each line
** Returns 1 if successful, 0 on error */
static int	read_map_content(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		height;

	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(game->map), 0);
	height = 0;
	while (height < game->map_height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map[height] = ft_strdup(line);
		if (!game->map[height])
			return (free_map(game->map, height), free(line), close(fd), 0);
		free(line);
		height++;
	}
	return (game->map[height] = NULL, close(fd), 1);
}

/* Main map parsing function that coordinates all validation
** Reads map, validates it, and sets up initial game state
** Returns 1 if map is valid and loaded, 0 on error */
int	parse_map(t_game *game, char *filename)
{
	if (!get_map_dimensions(game, filename))
		return (0);
	if (!read_map_content(game, filename))
		return (0);
	if (!validate_map(game))
	{
		free_map(game->map, game->map_height);
		game->map = NULL;
		return (0);
	}
	return (1);
}

/* Safely frees a 2D array up to the specified height
** Used for both map cleanup and temporary array cleanup */
void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (++i < height)
		free(map[i]);
	free(map);
}

/* Helper function for check_elements
** Updates player, exit positions and collectible count
** Modifies the counts array: [player_count, exit_count, collectibles] */
void	update_element_counts(t_game *game, int i, int j,
		int counts[3])
{
	if (game->map[i][j] == PLAYER)
	{
		counts[0]++;
		game->player_x = j;
		game->player_y = i;
	}
	else if (game->map[i][j] == EXIT)
	{
		counts[1]++;
		game->exit_x = j;
		game->exit_y = i;
	}
	else if (game->map[i][j] == COLLECT)
		counts[2]++;
}
