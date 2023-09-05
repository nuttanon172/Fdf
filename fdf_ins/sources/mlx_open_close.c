/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_open_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:59:52 by kaburale          #+#    #+#             */
/*   Updated: 2023/09/05 16:18:16 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	map_scale(t_data *data)
{
	int			a;
	int			b;

	a = WIDTH / 2 / data->map->width;
	b = HEIGHT / 2 / data->map->height;
	if (a < b)
		data->map->scale = a;
	else
		data->map->scale = b;
}

static int	win_exit_cross(t_data *data)
{
	free_ptr(data->map);
	mlx_destroy_image (data->mlx.mlx_ptr, data->mlx.img_ptr);
	mlx_destroy_window (data->mlx.mlx_ptr, data->mlx.win_ptr);
	exit (0);
}

static int	win_exit_esc(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		free_ptr(data->map);
		mlx_destroy_image (data->mlx.mlx_ptr, data->mlx.img_ptr);
		mlx_destroy_window (data->mlx.mlx_ptr, data->mlx.win_ptr);
		exit (0);
	}
	return (0);
}

static void	*img_create(t_data *data)
{
	data->mlx.img_ptr = mlx_new_image (data->mlx.mlx_ptr, WIDTH, HEIGHT);
	data->mlx.img_data = mlx_get_data_addr (data->mlx.img_ptr,
			&data->img.bits_per_pixel, &data->img.size_line, &data->img.endian);
	map_scale (data);
	map_draw (data->map, data);
	return (data->mlx.img_ptr);
}

void	mlx_open(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT,
			"FDF");
	data->mlx.img_ptr = img_create (data);
	mlx_put_image_to_window (data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img_ptr, 0, 0);
	mlx_key_hook (data->mlx.win_ptr, win_exit_esc, data);
	mlx_hook (data->mlx.win_ptr, 17, 0, win_exit_cross, data);
	mlx_loop (data->mlx.mlx_ptr);
}
