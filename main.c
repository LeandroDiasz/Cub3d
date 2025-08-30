/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:41:59 by leandrodias       #+#    #+#             */
/*   Updated: 2025/08/29 21:27:50 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (init_cub3d(&game, argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//start_game(&game);
	return (EXIT_SUCCESS);
}
