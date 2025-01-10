/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:52:19 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/10 14:18:14 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialize MLX and validate window dimensions*/
/* Create window with calculated dimensions */
static void	init_window(t_game *game)
{
	int	window_width;
	int	window_height;
	int	screen_width;
	int	screen_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("MLX initialization failed", game);
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	if (window_width > screen_width || window_height > screen_height)
	{
		free(game->mlx);
		error_exit("Map is too large for screen resolution", game);
	}
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			WINDOW_TITLE);
	if (!game->win)
	{
		free(game->mlx);
		error_exit("Window creation failed", game);
	}
}

/* Load all game sprites from XPM files  */
/* Verify all images loaded successfully */
/* Load each sprite and check for errors */
void	load_images(t_game *game)
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
}

/* Initialize window */
/* Load game sprites */
/* Setup event hooks */
void	init_game(t_game *game)
{
	init_window(game);
	load_images(game);
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
			mlx_destroy_window(game->mlx, game->win);
	}
	if (game->map)
		free_map(game->map, game->map_height);
}
