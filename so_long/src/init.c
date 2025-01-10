/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:52:19 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/10 11:56:26 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Get screen dimensions and validate window size */
static int	get_window_size(t_game *game, int *width, int *height)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	*width = game->map_width * TILE_SIZE;
	*height = game->map_height * TILE_SIZE;
	if (*width > screen_width || *height > screen_height)
		error_exit("Map is too large for screen resolution", game);
	return (1);
}

/* Initialize MLX and create window based on map dimensions */
/* Calculate window dimensions */
/* Create window with calculated dimensions */
static int	init_window(t_game *game)
{
	int	window_width;
	int	window_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("MLX initialization failed", game);
	if (!get_window_size(game, &window_width, &window_height))
	{
		free(game->mlx);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			WINDOW_TITLE);
	if (!game->win)
	{
		free(game->mlx);
		error_exit("Window creation failed", game);
	}
	return (1);
}

/* Load all game sprites from XPM files  */
/* Verify all images loaded successfully */
/* Load each sprite and check for errors */
int	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &width, &height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"assets/bone.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &width, &height);
	if (!game->img_player || !game->img_wall
		|| !game->img_collect || !game->img_exit)
		error_exit("Failed to load one or more sprites", game);
	return (1);
}

/* Initialize window */
/* Load game sprites */
/* Setup event hooks */
void	init_game(t_game *game)
{
	if (!init_window(game))
		error_exit("Failed to initialize window", game);
	if (!load_images(game))
		error_exit("Failed to load images", game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0L, handle_close, game);
	mlx_expose_hook(game->win, handle_expose, game);
}

/* Free sprites if they were loaded */
/* Destroy window if it was created */
/* Free map if it was allocated */
/* Don't free game->mlx - it's handled by mlx_destroy_window */
void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
	{
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->img_collect)
			mlx_destroy_image(game->mlx, game->img_collect);
		if (game->img_exit)
			mlx_destroy_image(game->mlx, game->img_exit);
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
	}
	if (game->map)
	{
		free_map(game->map, game->map_height);
		game->map = NULL;
	}
	game->mlx = NULL;
}
