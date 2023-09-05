/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:19:33 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/05 15:56:06 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080

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
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_map
{
	int	width;
	int	height;
	int	scale;
	int	z_max;
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
int			ft_atoi_sp(const char *str, t_map *map);

/* add_stack */
t_node_z	*new_node(char *str, t_map *map);
void		add_stack(t_node_z **stack, t_node_z *new);
void		add_line(char **line_sp, t_node_z **stack, t_map *map);
void		read_map(t_node_z **stack, t_map *map, int fd);

/* read_stack */
void		read_stack(t_node_z **stack, t_map *map);

#endif
