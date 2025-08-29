/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-29 19:23:37 by jpires-n          #+#    #+#             */
/*   Updated: 2025-08-29 19:23:37 by jpires-n         ###   ########.rio      */
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
