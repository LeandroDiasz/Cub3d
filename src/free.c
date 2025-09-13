/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:23:37 by jpires-n          #+#    #+#             */
/*   Updated: 2025/09/13 18:25:37 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	multi_free(void *first, ...)
{
	va_list	args;
	void	*ptr;

	va_start(args, first);
	ptr = first;
	while (ptr)
	{
		free(ptr);
		ptr = va_arg(args, void *);
	}
	va_end(args);
}

void	error_exit(const char *message, char **to_free)
{
	if (to_free)
	{
		free_matriz(to_free);
		to_free = NULL;
	}
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	free_matriz(char **matriz)
{
	int	i;

	if (!matriz)
		return ;
	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	cleanup_game(t_cub3d *game)
{
	if (!game)
		return ;
	
	// Libera texturas se foram alocadas
	if (game->no_texture)
	{
		free(game->no_texture);
		game->no_texture = NULL;
	}
	if (game->so_texture)
	{
		free(game->so_texture);
		game->so_texture = NULL;
	}
	if (game->we_texture)
	{
		free(game->we_texture);
		game->we_texture = NULL;
	}
	if (game->ea_texture)
	{
		free(game->ea_texture);
		game->ea_texture = NULL;
	}
	if (game->floor_color)
	{
		free(game->floor_color);
		game->floor_color = NULL;
	}
	if (game->ceiling_color)
	{
		free(game->ceiling_color);
		game->ceiling_color = NULL;
	}
	
	// Libera o arquivo (que inclui o mapa)
	if (game->file)
	{
		free_matriz(game->file);
		game->file = NULL;
		game->map = NULL; // map aponta para dentro de file
	}
}
