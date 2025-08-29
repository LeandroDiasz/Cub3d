#include "../../includes/parser.h"

static int	check_border(char **map)
{

}

int	check_wall(char **map)
{
	int		x;
	int		y;

	while (map[x])
	{
		x = 0;
		while (map[x][y])
		{
			if (map[x][y] == FLOOR)
			{
				if (map[x + 1][y] != WALL || map[x - 1][y] != WALL || map[x][y + 1] != WALL || map[x][y - 1] != WALL)
					return (0);
			}
			else if (map[x][y] != WALL && map[x][y] != FLOOR)
			{
				ft_printf("Error: Invalid character '%c' in map\n", map[x][y]);
				return (0);
			}
		}
		x++;
	}
}

int	check_elements(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	player;
	int	collectibles;

	j = 0;
	exit = 0;
	player = 0;
	collectibles = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (!check_aux(map[j][i], &exit, &player, &collectibles))
				return (0);
			i++;
		}
		j++;
	}
	if (player != 1 || exit != 1 || collectibles == 0)
		return (0);
	return (1);
}

int	check_aux(char element, int *exit, int *player, int *collectibles)
{
	if (element == EXIT)
		(*exit)++;
	else if (element == COLLECT)
		(*collectibles)++;
	else if (element == PLAYER)
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