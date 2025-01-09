/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:01:29 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/09 11:15:02 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Recursive flood fill algorithm to verify map reachability
** Marks visited cells with 'V' and counts collectibles
** Used by check_path to validate map is solvable */
void	flood_fill(char **map, int x, int y, int *collectibles)
{
	if (map[y][x] == WALL || map[y][x] == 'V')
		return ;
	if (map[y][x] == COLLECT)
		(*collectibles)++;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, collectibles);
	flood_fill(map, x - 1, y, collectibles);
	flood_fill(map, x, y + 1, collectibles);
	flood_fill(map, x, y - 1, collectibles);
}

/* Verifies map is surrounded by walls
** Checks first/last row and first/last column
** Returns 1 if walls are valid, 0 if not */
int	check_walls(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_width)
		if (game->map[0][i] != WALL ||
			game->map[game->map_height - 1][i] != WALL)
			return (0);
	i = 0;
	while (++i < game->map_height - 1)
		if (game->map[i][0] != WALL ||
			game->map[i][game->map_width - 1] != WALL)
			return (0);
	return (1);
}

/* Counts and validates required map elements
** Verifies exactly one player, one exit, and at least one collectible
** Updates game struct with positions and counts */
int	check_elements(t_game *game)
{
	int	i;
	int	j;
	int	counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
			update_element_counts(game, i, j, counts);
	}
	game->collectibles = counts[2];
	return (counts[0] == 1 && counts[1] == 1 && counts[2] > 0);
}

/* Creates map copy and uses flood fill to verify
** all collectibles and exit are reachable from player position
** Returns 1 if path exists to all required elements */
int	check_path(t_game *game)
{
	char	**map_copy;
	int		collectibles;
	int		exit_reachable;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * game->map_height);
	if (!map_copy)
		return (0);
	i = -1;
	while (++i < game->map_height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
			return (free_map(map_copy, i), 0);
	}
	collectibles = 0;
	flood_fill(map_copy, game->player_x, game->player_y, &collectibles);
	exit_reachable = (map_copy[game->exit_y][game->exit_x] == 'V');
	free_map(map_copy, game->map_height);
	return (collectibles == game->collectibles && exit_reachable);
}

/* Main validation function that coordinates all checks
** Returns 1 if map passes all validation, 0 if any check fails */
int	validate_map(t_game *game)
{
	if (!check_elements(game))
		return (0);
	if (!check_walls(game))
		return (0);
	return (check_path(game));
}
