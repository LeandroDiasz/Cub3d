/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:51:23 by jpires-n          #+#    #+#             */
/*   Updated: 2025/08/29 18:33:12 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	check_wall(char **map)
{
	int		x;
	int		y;
	int		len;

	x = 0;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == FLOOR)
				if (!check_neighbor(map, x, y))
					return (0);
			else if ((map[x][y] != WALL) && (map[x][y] != FLOOR) && (map[x][y] != PLAYER))
			{
				printf("Error: Invalid character '%c' in map\n", map[x][y]);
				return (0);
			}
			y++;
		}
		y = 0;
		x++;
	}
}

int	is_valid_neighbor(char c)
{
	return (c == WALL || c == FLOOR || c == PLAYER);
}

int	check_neighbor(char **map, int x, int y)
{
	if (x > 0 && !is_valid_neighbor(map[x - 1][y]))
		return (0);
	if (map[x + 1] && !is_valid_neighbor(map[x + 1][y]))
		return (0);
	if (y > 0 && !is_valid_neighbor(map[x][y - 1]))
		return (0);
	if (map[x][y + 1] && !is_valid_neighbor(map[x][y + 1]))
		return (0);
	return (1);
}

int	check_elements(char **map)
{
	int	y;
	int	x;
	int	player;

	x = 0;
	player = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!check_aux(map[x][y], &player))
				return (0);
			y++;
		}
		x++;
	}
	if (player != 1 || exit != 1)
		return (0);
	return (1);
}

int	check_aux(char element, int *player)
{
	if (element == PLAYER)
		(*player)++;
	else if (element != FLOOR && element != WALL)
		return (0);
	return (1);
}

int	check_ber(const char *file)
{
	int	i;
	int	j;

	if (!file && ft_strlen(file) < 4)
		error_exit("Error: null file or insufficient size", NULL);
	i = ft_strlen(file) - 4;
	j = 0;
	while (".ber"[j])
	{
		if (file[i + j] != ".ber"[j])
		{
			ft_printf("Error: Invalid extension. Use .ber\n");
			return (0);
		}
		j++;
	}
	return (1);
}
