# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 13:59:49 by ntairatt          #+#    #+#              #
#    Updated: 2023/09/09 17:50:54 by ntairatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX_DIR) -Iinclude

FRAMEWORK = -framework OpenGL -framework AppKit

SRCS	=	src/fdf.c \
			src/drawline.c \
			src/drawmap.c \
			src/error.c \
			src/ft_color.c \
			src/linear_gradient.c \
			src/map_init.c \
			src/mlx_init.c \
			src/read_map.c \
			src/read_stack.c

MLX	=	mlx/libmlx.a
MLX_DIR	=	mlx/

LIBFT	= libft/libft.a
LIBFT_DIR	=	libft/include

RM	=	rm -rf
$(NAME):
	@make -C libft
	@make -C mlx
	@$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(SRCS) $(FRAMEWORK) -o $(NAME)

.PHONY: all clean fclean re norm
all: $(NAME)

clean:
	@make clean -C libft
	@make clean -C mlx
	@$(RM) $(LIBFT) $(MLX) $(NAME)

fclean: clean

re: clean all

norm:
	@make norm -C libft
	@echo "---------------- FDF -----------------------"
	@norminette include src
	@echo "------------------------------------------\n"
