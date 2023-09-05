/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:32:54 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/05 17:56:26 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_scale(t_data *map)
{
	int	height;
	int	width;
	int	w;
	int	h;

	width = WIDTH;
	height = HEIGHT;
	if (width < 1000)
		width = 1000;
	if (height < 1000)
		height = 1000;
	w = width / 2 / map->width;
	h = height / 2 / map->height;
	if (w < h)
		map->scale = w;
	else
		map->scale = h;
}

void	mlx_init(t_data *fdf)
{
	fdf->mlx.mlx = mlx_init();
	fdf->mlx.window = mlx_new_window(fdf->mlx.mlx, WIDTH, HEIGHT, "FDF");
	fdf->img.img_ptr = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	fdf->img.img_addr = mlx_get_data_addr(fdf->img.img_ptr, 
			fdf->img.bits_per_pixel, fdf->img.line_length, fdf->img.endian);
	mlx_key_hook(fdf->img.img_ptr, key_esc, data);
	mlx_hook(fdf->mlx.window, 17, 0, win_cross, data);
	map_scale(fdf->map);
	/* map_draw here!!!*/
	mlx_loop(fdf->mlx.mlx);
}

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