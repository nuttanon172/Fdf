/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:12:00 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/10 11:38:19 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_init(t_data *fdf, int fd)
{
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (!fdf->map)
	{
		close(fd);
		map_error("Error: Map Initial Error", NULL, NULL);
	}
	fdf->map->width = 0;
	fdf->map->height = 0;
	fdf->map->scale = 0;
	fdf->map->z = NULL;
	fdf->map->color = NULL;
	fdf->map->fd = fd;
}
