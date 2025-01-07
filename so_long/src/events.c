/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:57:21 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/01 17:57:21 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function handles the win condition when player reaches exit */
/* First increment move counter since this is a valid move */
/* Check if all collectibles are gathered before exit */
static void	handle_exit(t_game *game)
{
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (game->collected == game->collectibles)
	{
		ft_printf("\nCongratulations! All bones collected!\n");
		ft_printf("Total moves: %d\n", game->moves);
		cleanup_game(game);
		exit(0);
	}
	else
		ft_printf("Collect all bones before exiting!\n");
}

/* Check if the next position is not a wall
** Check if next is a collectible
** Increment collected counter
** Replace with empty space
** Check and handle exit
** Update map with new player position
** Don't override exit with player
** Update player coordinates
** Increment move counter
** Print move counter */
static void	process_move(t_game *game, int new_x, int new_y)
{
	char	next_pos;

	next_pos = game->map[new_y][new_x];
	if (next_pos != WALL)
	{
		if (next_pos == COLLECT)
		{
			game->collected++;
			game->map[new_y][new_x] = '0';
			ft_printf("Bones: %d/%d\n",
				game->collected, game->collectibles);
		}
		else if (next_pos == EXIT)
		{
			handle_exit(game);
			return ;
		}
		game->map[game->player_y][game->player_x] = EMPTY;
		if (next_pos != EXIT)
			game->map[new_y][new_x] = PLAYER;
		game->player_x = new_x;
		game->player_y = new_y;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}

/* Exit game if ESC is pressed
** Handle directional movement
** Render updated game state */
int	handle_keypress(int keycode, t_game *game)
{
	ft_printf("Debug: Key pressed: %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		cleanup_game(game);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		process_move(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		process_move(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		process_move(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		process_move(game, game->player_x + 1, game->player_y);
	render_game(game);
	return (0);
}
/* Handle close button */
int	handle_close(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}
/* Handle window redraw */
int	handle_expose(t_game *game)
{
	render_game(game);
	return (0);
}
