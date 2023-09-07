/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:29:26 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/07 23:14:11 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_absolute(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_step(int cmp1, int cmp2)
{
	if (cmp1 < cmp2)
		return (1);
	return (-1);
}

void	point_init(t_point *d, t_point *u, t_point p1, t_point p2)
{
	u->x = ft_step(p1.x, p2.x);
	u->y = ft_step(p1.y, p2.y);
	d->x = ft_absolute(p2.x - p1.x);
	d->y = ft_absolute(p2.y - p1.y);
}

void	plot_pixel(t_data *fdf, int x, int y, int color)
{
	int	i;

	i = (x * fdf->img.bits_per_pixel / 8) + (y * fdf->img.line_len);
	fdf->img.img_addr[i] = color;
	fdf->img.img_addr[++i] = color >> 8;
	fdf->img.img_addr[++i] = color >> 16;
}

void	bresenham(t_point p1, t_point p2, t_data *fdf)
{
	t_point	distance;
	t_point	update;
	t_point	cur;
	int		error;
	int		e2;

	point_init(&distance, &update, p1, p2);
	error = distance.x - distance.y;
	cur = p1;
	while (1)
	{
		plot_pixel(fdf, cur.x, cur.y, get_color(cur, p1, p2, distance));
		if (cur.x == p2.x && cur.y == p2.y)
			break ;
		e2 = 2 * error;
		if (e2 > -distance.y)
		{
			error -= distance.y;
			cur.x += update.x;
		}
		if (e2 < distance.x)
		{
			error += distance.x;
			cur.y += update.y;
		}
	}
}
