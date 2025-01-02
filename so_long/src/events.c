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
static void    handle_exit(t_game *game)
{
    /* Check if all collectibles are gathered before allowing exit */
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

/* Process the movement and update game state */
static void    process_move(t_game *game, int new_x, int new_y)
{
    char    next_pos;

    next_pos = game->map[new_y][new_x];
    ft_printf("Debug: Trying to move to position with char: %c\n", next_pos);
    
    /* Check if the next position is not a wall */
    if (next_pos != WALL)
    {
        /* Handle collectible pickup */
        if (next_pos == COLLECT)
        {
            game->collected++;
            game->map[new_y][new_x] = '0';  // Replace collected item with empty space
            ft_printf("Bones collected: %d/%d\n", 
                game->collected, game->collectibles);
        }
        /* Handle exit */
        else if (next_pos == EXIT)
        {
            handle_exit(game);
            return;
        }
        
        /* Update map with new player position */
        game->map[game->player_y][game->player_x] = EMPTY;
        if (next_pos != EXIT)  // Don't override exit tile with player
            game->map[new_y][new_x] = PLAYER;
        game->player_x = new_x;
        game->player_y = new_y;
        game->moves++;
        ft_printf("Moves: %d\n", game->moves);
    }
}

/* Handle keyboard input for player movement */
int    handle_keypress(int keycode, t_game *game)
{
    ft_printf("Debug: Key pressed: %d\n", keycode);

    /* Exit game if ESC is pressed */
    if (keycode == KEY_ESC)
    {
        cleanup_game(game);
        exit(0);
    }
    
    /* Handle directional movement */
    else if (keycode == KEY_W || keycode == KEY_UP)
        process_move(game, game->player_x, game->player_y - 1);
    else if (keycode == KEY_S || keycode == KEY_DOWN)
        process_move(game, game->player_x, game->player_y + 1);
    else if (keycode == KEY_A || keycode == KEY_LEFT)
        process_move(game, game->player_x - 1, game->player_y);
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
        process_move(game, game->player_x + 1, game->player_y);
    
    /* Render the updated game state */
    render_game(game);
    return (0);
}

/* Handle window close button event */
int    handle_close(t_game *game)
{
    cleanup_game(game);
    exit(0);
    return (0);
}

/* Handle expose event */
int    handle_expose(t_game *game)
{
    render_game(game);
    return (0);
}

/* This function sets up all event hooks */
void    setup_events(t_game *game)
{
    /* Hook keyboard events */
    mlx_key_hook(game->win, handle_keypress, game);
    /* Hook window close button */
    mlx_hook(game->win, 17, 0L, handle_close, game);
    /* Hook expose event to redraw window */
    mlx_expose_hook(game->win, handle_expose, game);
}