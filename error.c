/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:49:43 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/03 18:23:07 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    exit_error(char *str)
{
	if (str)
	{
		ft_putendl_fd(str, 2);
    	exit(1);
	}
}

void	map_error(char *str, t_map *map, t_node_z *node)
{
	t_node_z	*tmp;

	if (map)
	{
		if (map->z_arr)
			free(map->z_arr);
		if (map->color_arr)
			free(map->color_arr);
		free(map);
	}
	if (node)
	{
		while (node)
		{
			tmp = node->next;
			free(node);
			node = tmp;
		}
	}
    exit_error(str);
}

void	free_2d(char **var)
{
	int	i;

	i = 0;
	while (var[i])
		free(var[i++]);
	free(var);
}
