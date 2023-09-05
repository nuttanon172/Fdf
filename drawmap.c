/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:45:54 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/05 18:18:05 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void iso(int *x, int *y, int z)
{
    int tmp_x;
    int tmp_y;

    tmp_x = x;
    tmp_y = y;
    *x = (tmp_x - tmp_y) * cos(0.46373398);
    *y = -z + (tmp_x + tmp_y) * sin(0.46373398);
}

void    draw_map(t_map *map, t_data *data)
{
    
}