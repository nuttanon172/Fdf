/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:03:35 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/03 23:06:11 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	win_cross(t_data *data)
{
	free_ptr(data->map);
	mlx_destroy_image(data->mlx.mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx.mlx, data->mlx.window);
	exit(0);
}

int	key_esc(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		free_ptr(data->map);
		mlx_destroy_image(data->mlx.mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx.mlx, data->mlx.window);
		exit(0);
	}
	return(0);
}
