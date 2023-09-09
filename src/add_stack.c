/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:35:05 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/09 10:48:04 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node_z	*new_node(char *str, t_map *map, t_node_z **stack)
{
	t_node_z	*node;
	char		**nbr;

	node = (t_node_z *)malloc(sizeof(t_node_z));
	if (!node)
		map_error("Error: Add Stack Error", map, *stack);
	nbr = ft_split(str, ',');
	if (!nbr || !ft_isvalid(nbr[0], 10) || (nbr[1] && !ft_isvalid(nbr[1], 16)))
	{
		free(node);
		map_error("Error: Add Stack Error", map, *stack);
	}
	node->z = ft_atoi(nbr[0]);
	node->color = -1;
	if (nbr[1])
		node->color = ft_atoi_base(nbr[1], 16);
	node->next = NULL;
	free_2d(nbr);
	return (node);
}

void	add_stack(t_node_z **stack, t_node_z *new)
{
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}

void	add_line(char **line_sp, t_node_z **stack, t_map *map)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	while (line_sp[i])
	{
		add_stack(stack, new_node(line_sp[i], map, stack));
		w++;
		i++;
	}
	if (!(map->width))
		map->width = w;
	if (map->width != w)
		map_error("Error: Read Map Error", map, *stack);
}

void	read_map(t_node_z **stack, t_map *map, int fd)
{
	char	*line;
	char	**line_sp;

	line = get_next_line(fd);
	while (line)
	{
		line_sp = ft_split(line, ' ');
		if (!line_sp)
		{
			map_error("Error: Read Map Error", map, *stack);
			free(line);
		}
		add_line(line_sp, stack, map);
		free(line);
		free_2d(line_sp);
		map->height++;
		line = get_next_line(fd);
	}
	if (!*stack)
		map_error("Error: Read Map Error", map, *stack);
}
