/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:29:26 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/09 18:20:11 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_absolute(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

int	ft_step(int cmp1, int cmp2)
{
	if (cmp1 < cmp2)
		return (1);
	return (-1);
}

void	point_init(t_point *p1, t_point *p2, t_point *delta)
{
	p1->x_update = ft_step(p1->x, p2->x);
	p1->y_update = ft_step(p1->y, p2->y);
	delta->x = ft_absolute(p2->x - p1->x);
	delta->y = ft_absolute(p2->y - p1->y);
}

void	plot_pixel(t_data *fdf, int x, int y, int color)
{
	int	i;

	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		i = (x * fdf->img.bits_per_pixel / 8) + (y * fdf->img.line_len);
		fdf->img.img_addr[i] = color;
		fdf->img.img_addr[++i] = color >> 8;
		fdf->img.img_addr[++i] = color >> 16;
	}
}

void	bresenham(t_point p1, t_point p2, t_data *fdf)
{
	t_point	cur;
	t_point	delta;
	int		error;
	int		e2;

	point_init(&p1, &p2, &delta);
	error = delta.x - delta.y;
	cur = p1;
	while (1)
	{
		plot_pixel(fdf, cur.x, cur.y, get_color(cur, p1, p2, delta));
		if (cur.x == p2.x && cur.y == p2.y)
			break ;
		e2 = 2 * error;
		if (e2 > -delta.y)
		{
			error -= delta.y;
			cur.x += p1.x_update;
		}
		if (e2 < delta.x)
		{
			error += delta.x;
			cur.y += p1.y_update;
		}
	}
}
