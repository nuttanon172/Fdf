/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:45:54 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/09 10:51:23 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_bg(t_data *fdf)
{
	int	i;
	int	*bg_color;

	i = 0;
	ft_bzero(fdf->img.img_addr,
		(WIDTH * HEIGHT) * (fdf->img.bits_per_pixel / 8));
	bg_color = (int *)fdf->img.img_addr;
	while (i < (WIDTH * HEIGHT))
	{
		bg_color[i] = BG_COLOR;
		i++;
	}
}

void	iso(int *x, int *y, int z)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(0.46373398);
	*y = -z + (tmp_x + tmp_y) * sin(0.46373398);
}

t_point	get_point(int x, int y, t_data *fdf)
{
	t_point	p;
	int		i;

	i = (y * fdf->map->width) + x;
	p.x = x;
	p.y = y;
	p.z = fdf->map->z[i];
	if (fdf->stack->color == -1)
		p.color = LINE_COLOR;
	else
		p.color = fdf->map->color[i];
	return (p);
}

t_point	projection(t_point p, t_data *fdf)
{
	p.x *= fdf->map->scale;
	p.y *= fdf->map->scale;
	p.z *= fdf->map->scale;
	p.x -= (fdf->map->width * fdf->map->scale) / 2;
	p.y -= (fdf->map->height * fdf->map->scale) / 2;
	iso(&p.x, &p.y, p.z);
	p.x += WIDTH / 2;
	p.y += HEIGHT / 2;
	return (p);
}

void	draw_map(t_data *fdf)
{
	int	x;
	int	y;

	y = 0;
	set_bg(fdf);
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x != fdf->map->width - 1)
				bresenham(projection(get_point(x, y, fdf), fdf),
					projection(get_point(x + 1, y, fdf), fdf), fdf);
			if (y != fdf->map->height - 1)
				bresenham(projection(get_point(x, y, fdf), fdf),
					projection(get_point(x, y + 1, fdf), fdf), fdf);
			x++;
		}
		y++;
	}
}
