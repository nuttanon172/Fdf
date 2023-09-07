/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:19:33 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/07 22:29:00 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1000
# define HEIGHT 1000
# define BG_COLOR	0x30221D
# define LINE_COLOR	0xF7F5BC

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	x_init;
	int	y_init;
	int	x_end;
	int	y_end;
	int	color;
}				t_point;

typedef struct s_node_z
{
	int					z;
	int					color;
	struct s_node_z		*next;
}				t_node_z;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_map
{
	int	width;
	int	height;
	int	scale;
	int	*z;
	int	*color;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}				t_mlx;

typedef struct s_data
{
	t_mlx		mlx;
	t_img		img;
	t_map		*map;
	t_node_z	*stack;
}				t_data;

/* error */
void		exit_error(char *str);
void		map_error(char *str, t_map *map, t_node_z *node);
void		free_map(t_map *map);
void		free_2d(char **var);

/* ft_atoi_sp */
int			ft_ishex(char *s);
int			base_check(char c, int base_num);
int			ft_isvalid(char *s, int base);
int			ft_atoi_base(char *str, int base_num);
int			ft_atoi_sp(const char *str, t_map *map, t_node_z **stack);

/* add_stack */
t_node_z	*new_node(char *str, t_map *map, t_node_z **stack);
void		add_stack(t_node_z **stack, t_node_z *new);
void		add_line(char **line_sp, t_node_z **stack, t_map *map);
void		read_map(t_node_z **stack, t_map *map, int fd);

/* read_stack */
void		read_stack(t_node_z **stack, t_map *map);

/* mlx_init */
void		map_scale(t_map *map);
void		mlx_fdf(t_data *fdf);
void		win_cross(t_data *data);
int			key_esc(int keycode, t_data *data);

/* drawmap */
t_point		projection(t_point p, t_data *fdf);
void		draw_map(t_data *fdf);

/* drawline */
void		bresenham(t_point p1, t_point p2, t_data *data);

/* linear_gradient */
int			get_color(t_point current, t_point start, t_point end, t_point delta);

/* mlx_init */
void		map_init(t_data *fdf);

#endif
