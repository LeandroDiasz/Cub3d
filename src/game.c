/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leandrodias <leandrodias@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:52:19 by leandrodias       #+#    #+#             */
/*   Updated: 2025/06/10 16:56:56 by leandrodias      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int    start_game(t_cub3d *game)
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
	render_map(&game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, \
	&handle_close, &game);
	mlx_loop(game->mlx);
    return (EXIT_SUCCESS);
}