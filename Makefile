# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 12:46:46 by msimoes           #+#    #+#              #
#    Updated: 2025/08/20 16:38:28 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLXIP= ./init_mlx/
MLXI = $(MLXIP)initiate_mlx.c $(MLXIP)sprites.c  $(MLXIP)moves.c

PARP = ./parsing/
PAR = $(PARP)flood_fill.c $(PARP)main_parser.c $(PARP)parsing.c \
		$(PARP)init_struct.c

GNLP = ./gnl/
GNL = $(GNLP)get_next_line.c $(GNLP)get_next_line_utils.c

EXTP = ./srcs/
EXT = $(EXTP)ft_split.c $(EXTP)ft_strjoin.c $(EXTP)ft_bzero.c \
		$(EXTP)ft_calloc.c $(EXTP)ft_strlen.c $(EXTP)ft_strdup.c

NAME = so_long
SRCS = so_long.c errors.c allocation_handle.c $(PAR) $(GNL) $(EXT) $(MLXI)

COMP_LIB = ar rcs
RM = rm -f
CC = cc
CC_FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lXext -lX11
MLX_ARCH = minilibx-linux/libmlx_Linux.a

OBJS = $(SRCS:.c=.o)

%.o : %.c
	@ $(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(EXT_PATH) $(OBJS_EXT) $(MLX_ARCH)
	@ $(CC) $(CC_FLAGS) $(OBJS) $(MLX_ARCH) $(MLX_FLAGS) -o $(NAME) | echo "Compiled"

$(MLX_ARCH):
	@ cd $(dir $@) && make

all: $(NAME)

clean:
	@ $(RM) $(OBJS) $(EXT_PATH)$(OBJS_EXT)

fclean: clean
	@ $(RM) $(NAME) $(EXT_PATH)$(OBJS_EXT) | echo "Cleaned"

re: fclean all

.PHONY: all clean fclean re