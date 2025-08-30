/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:23:37 by jpires-n          #+#    #+#             */
/*   Updated: 2025/08/29 19:10:09 by ledias-d         ###   ########.fr       */
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
		free_matriz(to_free);
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
