/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:52:12 by ntairatt          #+#    #+#             */
/*   Updated: 2023/08/09 16:54:14 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isfdf(char *file_name)
{
	char	*type;
	int		i;
	int		check;

	type = ".fdf";
	check = 1;
	i = ft_strlen(file_name) - 4;
	if (i <= 0)
		return (check);
	else if (!ft_strncmp(&file_name[i], type, 4) && file_name[i])
		check = 0;
	return (check);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + (x * data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	win_exit_esc(int keycode, t_mlx *data)
{
	/* free sth */
	if (keycode == 53)
		exit (0);
}

int	win_exit_cross(t_mlx *data)
{
	/* free sth */
	exit (0);
}

int	main(int argc, char **argv)
{
	t_mlx	var;
	t_mlx	var_mlx;
	int 	i;

	//if (argc != 2 || ft_isfdf(argv[1]))
	//	exit(EXIT_SUCCESS);
	var_mlx.mlx = mlx_init();
	var_mlx.win = mlx_new_window(var_mlx.mlx, WIDTH, HEIGHT, "fdf");
	var_mlx.img_ptr = mlx_new_image(var_mlx.mlx, WIDTH, HEIGHT);
	var_mlx.img_addr = mlx_get_mlx_addr(var_mlx.img_ptr, &var.bits_per_pixel,
							&var.line_length, &var.endian);
	i = (WIDTH * 25 / 100);
    while (i < (WIDTH * 75 / 100))
		my_mlx_pixel_put(&var_mlx, i++, (HEIGHT / 2), 0x00FF00);     
	mlx_put_image_to_window(var_mlx.mlx, var_mlx.win, var_mlx.img_ptr, 0, 0);
	mlx_key_hook (var_mlx.win, win_exit_esc, &var_mlx);
	mlx_hook (var_mlx.win, 17, 0, win_exit_cross, &var_mlx);
	mlx_loop(var_mlx.mlx);
}
