# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 13:59:49 by ntairatt          #+#    #+#              #
#    Updated: 2023/07/24 16:31:57 by ntairatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC	=	cc

CFLAGS	=	-I$(LIBFT_DIR) -I$(MLX_DIR)
#CFLAGS	=	-Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX_DIR)

FW = -framework OpenGL -framework AppKit

SRCS	=	fdf.c

MLX	=	mlx/libmlx.a
MLX_DIR	=	mlx

LIBFT	= libft/libft.a
LIBFT_DIR	=	libft/include

RM	=	rm -rf
$(NAME):
	@make -C libft
	@make -C mlx
	$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(SRCS) $(FW) -o $(NAME)

.PHONY: all clean fclean re norm
all: $(NAME)

clean:
	@make clean -C libft
	@make clean -C mlx
	@$(RM) $(LIBFT) $(MLX) $(NAME)

fclean: clean

re: clean all

norm:
