/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:26:11 by kaburale          #+#    #+#             */
/*   Updated: 2023/08/09 19:09:41 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	malloc_check(t_map *map)
{
	if (!map->z_arr || !map->color_arr)
	{
		if (map->z_arr)
			free(map->z_arr);
		if (map->color_arr)
			free(map->color_arr);
		exit_error_free(READ_ARRAY_ERROR, map);
	}
}

static int	update_max(int pop, int max)
{
	if (pop > max)
		return (pop);
	return (max);
}

static t_node_z	*stack_pop(t_node_z **stack)
{
	t_node_z	*pop_node;

	pop_node = NULL;
	if (stack && *stack)
	{
		pop_node = *stack;
		*stack = (*stack)->next;
	}
	return (pop_node);
}

void	map_read_array(t_node_z **stack, t_map *map)
{
	size_t		i;
	size_t		size;
	t_node_z	*pop_node;

	size = (map->width * map->height) * sizeof(int);
	map->z_arr = (int *)malloczero(size);
	map->color_arr = (int *)malloczero(size);
	malloc_check(map);
	i = (map->width * map->height) - 1;
	while (1)
	{
		pop_node = stack_pop(stack);
		if (pop_node)
		{
			map->z_arr[i] = pop_node->z;
			map->color_arr[i] = pop_node->color;
			map->z_max = update_max(pop_node->z, map->z_max);
		}
		else
			break ;
		i--;
		free(pop_node);
	}
}

int	ft_atoi_sp(const char *str, t_map *map)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\v' || str[i] == '\f' || str[i] == '\n' || str[i]
		== '\r' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		exit_error_free(NEW_STACK_ERROR, map);
	return (nb * sign);
}
