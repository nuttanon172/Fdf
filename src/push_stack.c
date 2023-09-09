/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:35:05 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/09 16:22:13 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node_z	*new_node(char *str, t_map *map, t_node_z **stack)
{
	t_node_z	*node;
	char		**nbr;

	node = (t_node_z *)malloc(sizeof(t_node_z));
	if (!node)
		return (NULL);
	nbr = ft_split(str, ',');
	if (!nbr || !ft_format(nbr[0], 10) || (nbr[1] && !ft_format(nbr[1], 16)))
	{
		free(node);
		free_2d(nbr);
		map_error("Error: Add Stack Error", map, *stack);
	}
	node->z = ft_atoi(nbr[0]);
	node->color = -1;
	if (nbr[1])
		node->color = ft_color(nbr[1], 16);
	node->next = NULL;
	free_2d(nbr);
	return (node);
}

int	push(t_node_z **stack, t_node_z *new)
{
	if (!new)
		return (0);
	new->next = *stack;
	*stack = new;
	return (1);
}

void	add_line(char **line_sp, char *line, t_node_z **stack, t_map *map)
{
	int	w;
	int	i;

	w = 0;
	i = -1;
	while (line_sp[++i])
	{
		if (!push(stack, new_node(line_sp[i], map, stack)))
		{
			free(line);
			free_2d(line_sp);
			map_error("Error: Add Stack Error", map, *stack);
		}
		w++;
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
			free(line);
			map_error("Error: Read Map Error", map, *stack);
		}
		add_line(line_sp, line, stack, map);
		free(line);
		free_2d(line_sp);
		map->height++;
		line = get_next_line(fd);
	}
}
