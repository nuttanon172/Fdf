/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:52:12 by ntairatt          #+#    #+#             */
/*   Updated: 2023/09/10 11:46:24 by ntairatt         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	fdf;
	int		fd;

	if (ac != 2 || ft_isfdf(av[1]))
		exit_error("Error: Input or File Format incorrect");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_error("Error: Open file error");
	fdf.stack = NULL;
	map_init(&fdf, fd);
	read_map(&fdf.stack, fdf.map);
	read_stack(&fdf.stack, fdf.map);
	mlx_fdf(&fdf);
	return (0);
}
