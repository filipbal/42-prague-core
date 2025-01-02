/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:01:47 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/01 18:01:47 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Validate each character in the map */
int	validate_chars(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (!ft_strchr("01CEP", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Check if the map is rectangular */
int	validate_rectangle(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (ft_strlen(map[i]) != (size_t)width)
			return (0);
		i++;
	}
	return (1);
}

/* Validate map dimensions */
int	validate_dimensions(int height, int width)
{
	if (height < 3 || width < 3)
		return (0);
	/* Adjusted max dimensions for 64x64 tiles */
	/* Max window size consideration:
	 * Width: 30 * 64 = 1920 pixels (standard screen width)
	 * Height: 16 * 64 = 1024 pixels (comfortable height) */
	if (height > 16 || width > 30)
		return (0);
	return (1);
}

/* Count specific elements in map */
void	count_elements(t_game *game, int *player, int *exit)
{
	int	i;
	int	j;

	*player = 0;
	*exit = 0;
	game->collectibles = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == PLAYER)
			{
				game->player_x = j;
				game->player_y = i;
				(*player)++;
			}
			else if (game->map[i][j] == EXIT)
			{
				game->exit_x = j;
				game->exit_y = i;
				(*exit)++;
			}
			else if (game->map[i][j] == COLLECT)
				game->collectibles++;
		}
	}
}

/* Complete map validation */
int	validate_map(t_game *game)
{
	int	player_count;
	int	exit_count;

	if (!validate_dimensions(game->map_height, game->map_width))
		return (0);
	if (!validate_rectangle(game->map, game->map_height, game->map_width))
		return (0);
	if (!validate_chars(game->map, game->map_height, game->map_width))
		return (0);
	
	count_elements(game, &player_count, &exit_count);
	
	if (player_count != 1 || exit_count != 1 || game->collectibles < 1)
		return (0);
	
	return (1);
}