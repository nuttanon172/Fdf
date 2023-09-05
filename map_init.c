/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:12:00 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/03 23:05:50 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_init(t_map *map)
{
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		map_error("Error: Map Initial Error", NULL, NULL);
	map->width = 0;
	map->height = 0;
	map->scale = 0;
	map->z_max = 0;
	map->z = NULL;
	map->color = NULL;
}
