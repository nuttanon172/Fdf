/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:43:26 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/09 16:57:51 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node_z	*pop(t_node_z **stack)
{
	t_node_z	*node;

	node = NULL;
	if (stack && *stack)
	{
		node = *stack;
		*stack = (*stack)->next;
	}
	return (node);
}

void	read_stack(t_node_z **stack, t_map *map)
{
	t_node_z	*node;
	int			i;

	map->z = (int *)malloc((map->width * map->height) * sizeof(int));
	map->color = (int *)malloc((map->width * map->height) * sizeof(int));
	if (!(map->z) || !(map->color))
		map_error("Error: Read Stack Error", map, *stack);
	i = map->width * map->height - 1;
	while (1)
	{
		node = pop(stack);
		if (!node)
			break ;
		map->z[i] = node->z;
		map->color[i] = node->color;
		free(node);
		i--;
	}
}
