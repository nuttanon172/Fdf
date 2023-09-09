/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:32:54 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/09 16:57:00 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_scale(t_map *map)
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

void	mlx_fdf(t_data *fdf)
{
	fdf->mlx.mlx = mlx_init();
	fdf->mlx.window = mlx_new_window(fdf->mlx.mlx, WIDTH, HEIGHT, "FDF");
	fdf->img.img_ptr = mlx_new_image(fdf->mlx.mlx, WIDTH, HEIGHT);
	fdf->img.img_addr = mlx_get_data_addr(fdf->img.img_ptr,
			&fdf->img.bits_per_pixel, &fdf->img.line_len, &fdf->img.endian);
	map_scale(fdf->map);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.window, fdf->img.img_ptr,
		0, 0);
	mlx_key_hook(fdf->mlx.window, key_esc, fdf);
	mlx_hook(fdf->mlx.window, 17, 0, win_cross, fdf);
	mlx_loop(fdf->mlx.mlx);
}

int	win_cross(t_data *fdf)
{
	free_map(fdf->map);
	mlx_destroy_image(fdf->mlx.mlx, fdf->img.img_ptr);
	mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.window);
	exit(0);
}

int	key_esc(int keycode, t_data *fdf)
{
	if (keycode == 53)
	{
		free_map(fdf->map);
		mlx_destroy_image(fdf->mlx.mlx, fdf->img.img_ptr);
		mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.window);
		exit(0);
	}
	return (0);
}
