/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:52:19 by leandrodias       #+#    #+#             */
/*   Updated: 2025/09/13 18:25:37 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_struct(t_cub3d *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->map = NULL;
	game->file = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->player_dir = -1;
	game->map_width = 0;
	game->map_height = 0;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
	game->floor_rgb = -1;
	game->ceiling_rgb = -1;
}

int	init_cub3d(t_cub3d *game, char *file)
{
	int		player_x;
	int		player_y;

	player_x = 0;
	player_y = 0;
	init_struct(game);
	game->file = file_read(file);
	if (!game->file)
	{
		cleanup_game(game);
		error_exit("Error reading the file", NULL);
	}
	if (!cub_validate(game->file, game))
	{
		cleanup_game(game);
		error_exit("Invalid file", NULL);
	}
	if (!map_validate(game->map))
	{
		cleanup_game(game);
		error_exit("Invalid map", NULL);
	}
	find_player(game->map, &player_y, &player_x);
	game->player_x = player_x;
	game->player_y = player_y;
	return (1);
}
/*int    start_game(t_cub3d *game)
{
    if (!game)
    {
        ft_putstr_fd("Error: Game initialization failed\n", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->height * 64, \
	game->height * 64, WIN_NAME);
	load_sprites(&game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, \
	&handle_close, &game);
	mlx_loop(game->mlx);
    return (EXIT_SUCCESS);
}*/
