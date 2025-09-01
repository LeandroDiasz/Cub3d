/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:13:02 by codespace         #+#    #+#             */
/*   Updated: 2025/09/01 17:52:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	**file_generate(char **file, int fd)
{
    char	*line;
    int		i;

    i = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        file[i] = line;
        i++;
        line = get_next_line(fd);
    }
    free (line);
    file[i] = NULL;
    return (file);
}
char	**file_read(char *file)
{
	int		fd;
	int		lines;
	char	**file_arc;

	if (!check_ext(file))
		error_exit("Invalid extension. Use .cub\n", NULL);
	lines = count_lines(file);
	if (lines <= 0)
		return (NULL);
	file_arc = (char **)ft_calloc(lines + 1, sizeof(char *));
	if (!file_arc)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_matriz(file_arc);
		return (NULL);
	}
	if (!file_generate(file_arc, fd))
	{
		free_matriz(file_arc);
		return (NULL);
	}
	close (fd);
	return (file_arc);
}
