/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:54:28 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/01 17:54:28 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Verifies that the map is rectangular and surrounded by walls */
static int	check_walls(t_game *game)
{
	int	i;

	i = -1;
	/* Check first and last row */
	while (++i < game->map_width)
		if (game->map[0][i] != WALL || 
			game->map[game->map_height - 1][i] != WALL)
			return (0);
	i = 0;
	/* Check first and last column */
	while (++i < game->map_height - 1)
		if (game->map[i][0] != WALL || 
			game->map[i][game->map_width - 1] != WALL)
			return (0);
	return (1);
}

/* Count map elements and verify required components exist exactly once */
static int	check_elements(t_game *game)
{
	int	i;
	int	j;
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	game->collectibles = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == PLAYER && ++player_count)
			{
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->map[i][j] == EXIT && ++exit_count)
			{
				game->exit_x = j;
				game->exit_y = i;
			}
			else if (game->map[i][j] == COLLECT)
				game->collectibles++;
		}
	}
	return (player_count == 1 && exit_count == 1 && game->collectibles > 0);
}

/* Recursive flood fill to verify all elements are reachable */
static void	flood_fill(char **map, int x, int y, int *collectibles)
{
	/* If we hit a wall or already visited cell, return */
	if (map[y][x] == WALL || map[y][x] == 'V')
		return ;
	
	/* If we found a collectible, count it */
	if (map[y][x] == COLLECT)
		(*collectibles)++;
	
	/* Mark current cell as visited */
	map[y][x] = 'V';
	
	/* Recursively check all adjacent cells */
	flood_fill(map, x + 1, y, collectibles);
	flood_fill(map, x - 1, y, collectibles);
	flood_fill(map, x, y + 1, collectibles);
	flood_fill(map, x, y - 1, collectibles);
}

/* Create a copy of the map for flood fill validation */
static char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * game->map_height);
	if (!map_copy)
		return (NULL);
	i = -1;
	while (++i < game->map_height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			free_map(map_copy, i);
			return (NULL);
		}
	}
	return (map_copy);
}

/* Verify that all collectibles and exit are reachable */
static int	check_path(t_game *game)
{
	char	**map_copy;
	int		collectibles;
	int		exit_reachable;

	map_copy = copy_map(game);
	if (!map_copy)
		return (0);
	
	collectibles = 0;
	flood_fill(map_copy, game->player_x, game->player_y, &collectibles);
	
	/* Check if exit is reachable (marked as 'V' after flood fill) */
	exit_reachable = (map_copy[game->exit_y][game->exit_x] == 'V');
	
	free_map(map_copy, game->map_height);
	return (collectibles == game->collectibles && exit_reachable);
}

/* Parse map file and validate its contents */
int    parse_map(t_game *game, char *filename)
{
    int        fd;
    char    *line;
    int        height;
    char    *trimmed_line;
    
    /* Open and read map file */
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Debug: Failed to open file %s\n", filename);
        return (0);
    }
    
    /* Get map dimensions and check rectangular shape */
    height = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        
        /* Remove newline if present */
        trimmed_line = ft_strtrim(line, "\n");
        if (!trimmed_line)
        {
            free(line);
            close(fd);
            return (0);
        }
        
        if (height == 0)
        {
            game->map_width = ft_strlen(trimmed_line);
            ft_printf("Debug: First line length: %d\n", game->map_width);
            ft_printf("Debug: First line content: '%s'\n", trimmed_line);
        }
        else if ((int)ft_strlen(trimmed_line) != game->map_width)
        {
            ft_printf("Debug: Line %d has different length. Expected %d, got %d\n", 
                     height + 1, game->map_width, (int)ft_strlen(trimmed_line));
            ft_printf("Debug: Line content: '%s'\n", trimmed_line);
            free(line);
            free(trimmed_line);
            close(fd);
            return (0);
        }
        free(line);
        free(trimmed_line);
        height++;
    }
    ft_printf("Debug: Map height: %d\n", height);
    close(fd);
    
    /* Allocate memory for map */
    game->map_height = height;
    game->map = (char **)malloc(sizeof(char *) * (height + 1));
    if (!game->map)
        return (0);
    
    /* Read map content */
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(game->map);
        return (0);
    }
    
    height = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        
        /* Remove newline if present */
        trimmed_line = ft_strtrim(line, "\n");
        if (!trimmed_line)
        {
            free(line);
            free_map(game->map, height);
            close(fd);
            return (0);
        }
        
        game->map[height] = trimmed_line;
        free(line);
        height++;
    }
    game->map[height] = NULL;  /* NULL terminate the array */
    close(fd);
    
    ft_printf("Debug: Map loaded. Validating...\n");
    /* Validate map */
    if (!check_walls(game) || !check_elements(game) || !check_path(game))
    {
        ft_printf("Debug: Map validation failed\n");
        if (!check_walls(game))
            ft_printf("Debug: Wall check failed\n");
        if (!check_elements(game))
            ft_printf("Debug: Elements check failed\n");
        if (!check_path(game))
            ft_printf("Debug: Path check failed\n");
        free_map(game->map, game->map_height);
        game->map = NULL;
        return (0);
    }
    
    ft_printf("Debug: Map validation successful\n");
    return (1);
}

/* Free allocated map memory */
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