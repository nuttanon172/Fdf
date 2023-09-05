/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:43:26 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/03 22:53:33 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_max(int max, int new)
{
	if (max < new)
		return (new);
	return (max);
}

t_node_z	*pop(t_node_z **stack)
{
	t_node_z	*node;

	node = NULL;
	if (stack && *stack)
	{
		node = *stack;
		node->next = NULL;
		*stack = *stack->next;
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
		map_error("Error: Read Stack Error");
	i = map->width * map->height - 1;
	while (i)
	{
		node = pop(stack);
		map->z[i] = node->z;
		map->color = node->color;
		map->z_max = ft_max(map->z_max, map->z[i]);
		free(node);
		i--;
	}
}
