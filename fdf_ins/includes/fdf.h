/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:49:57 by kaburale          #+#    #+#             */
/*   Updated: 2023/09/05 11:46:11 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "error.h"
# include "libft.h"

# define WIDTH		1000
# define HEIGHT 	1000

# define BG_COLOR	0x30221D
# define LINE_COLOR	0xF7F5BC

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct s_node_z
{
	int					z;
	int					color;
	struct s_node_z		*next;
}						t_node_z;

typedef struct s_map
{
	int					width;
	int					height;
	int					scale;
	int					z_max;
	int					*z_arr;
	int					*color_arr;
}						t_map;

typedef struct s_img
{
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_img;

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_data;
}						t_mlx;

typedef struct s_data
{
	t_map				*map;
	t_node_z			*stack;
	t_img				img;
	t_mlx				mlx;
}						t_data;

void		free_split(char **ptr);
void		free_ptr(t_map *map);
void		exit_error(char *str);
void		exit_error_free(char *str, t_map *map);
void		exit_error_free_2(char *str, t_map *map, t_node_z *ptr);
t_map		*map_init(t_map *map);
int			map_read_stack(t_node_z **stack, t_map *map, int fd);
t_node_z	*stack_new(char *str, t_map *map);
void		map_read_array(t_node_z **stack, t_map *map);
void		mlx_open(t_data *data);
void		map_draw(t_map *map, t_data *data);
void		draw_line(t_point p1, t_point p2, t_data *data);
int			get_color(t_point cur, t_point start, t_point end,
				t_point distance);
int			absolute(int nb);
int			ft_atoi_sp(const char *str, t_map *map);
#endif
