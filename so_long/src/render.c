/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:58:27 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/01 17:58:27 by fbalakov         ###   ########.fr       */
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
static void	render_tile(t_game *game, void *img, int x, int y)
{
	/* Convert tile coordinates to pixel positions */
	int	pixel_x;
	int	pixel_y;

	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	
	/* Put the image at calculated pixel position */
	mlx_put_image_to_window(game->mlx, game->win, img, pixel_x, pixel_y);
}

/* Render the background (empty spaces) of the map */
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
			/* We use wall sprite for walls, empty space for everything else */
			if (game->map[y][x] == WALL)
				render_tile(game, game->img_wall, x, y);
			x++;
		}
		y++;
	}
}

/* Render all game elements on top of background */
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
			/* Render each game element based on map character */
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

/* Main rendering function that updates the entire game display */
void	render_game(t_game *game)
{
	/* Clear the window before rendering new frame */
	mlx_clear_window(game->mlx, game->win);
	
	/* First render the background (walls and empty spaces) */
	render_background(game);
	
	/* Then render game elements on top */
	render_elements(game);
}

/* Optional: Add visual feedback for successful collection */
void	render_collection_effect(t_game *game, int x, int y)
{
	/* Here you could add a simple visual effect when collecting socks */
	/* For example, temporarily showing a different sprite or color */
	/* This is left as a potential enhancement */
	(void)game;
	(void)x;
	(void)y;
}

/* Optional: Add visual feedback when trying to exit without all collectibles */
void	render_exit_blocked(t_game *game)
{
	/* Visual feedback when player can't exit yet */
	/* Could display a message or effect near the exit */
	/* This is left as a potential enhancement */
	(void)game;
}