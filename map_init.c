/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:12:00 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/07 22:11:40 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_init(t_data *fdf)
{
	fdf->map = (t_map *)malloc(sizeof(t_map));
	if (!fdf->map)
		map_error("Error: Map Initial Error", NULL, NULL);
	fdf->map->width = 0;
	fdf->map->height = 0;
	fdf->map->scale = 0;
	fdf->map->z = NULL;
	fdf->map->color = NULL;
}
