/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:58:27 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/09 11:30:02 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:00:00 by your_login        #+#    #+#             */
/*   Updated: 2024/01/01 10:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Helper function to render a single tile at given coordinates */
/* Convert tile coordinates to pixel positions */
/* Put the image at calculated pixel position */
static void	render_tile(t_game *game, void *img, int x, int y)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, img, pixel_x, pixel_y);
}

/* Render wall sprite and empty space for everything else */
static void	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == WALL)
				render_tile(game, game->img_wall, x, y);
			x++;
		}
		y++;
	}
}

/* Render each game element based on map character */
static void	render_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == PLAYER)
				render_tile(game, game->img_player, x, y);
			else if (game->map[y][x] == COLLECT)
				render_tile(game, game->img_collect, x, y);
			else if (game->map[y][x] == EXIT)
				render_tile(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
}

/* Clear the window before rendering new frame
** Render the background (walls and empty)
** Then render game elements on top */
void	render_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_background(game);
	render_elements(game);
}
