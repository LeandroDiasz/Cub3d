/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:52:19 by leandrodias       #+#    #+#             */
/*   Updated: 2025/09/01 17:50:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_cub3d(t_cub3d *game, char *file)
{
	int		player_x;
	int		player_y;

	player_x = 0;
	player_y = 0;
	game->file = file_read(file);
	if (!game->file)
		error_exit("Error reading the file", game->map);
	if (!cub_validate(game->file, game))
		error_exit("Invalid file", game->file);
	if (!map_validate(game->map))
		error_exit("Invalid map", game->map);
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
