/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:49:43 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/09 16:34:31 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(char *str)
{
	if (str)
	{
		ft_putendl_fd(str, 2);
		exit(1);
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->z)
			free(map->z);
		if (map->color)
			free(map->color);
		free(map);
	}
}

void	map_error(char *str, t_map *map, t_node_z *node)
{
	t_node_z	*tmp;

	free_map(map);
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
	if (var)
	{
		while (var[i])
			free(var[i++]);
		free(var);
	}
}
