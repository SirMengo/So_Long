# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 12:46:46 by msimoes           #+#    #+#              #
#    Updated: 2026/05/20 14:45:32 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLXIP = ./init_mlx/
MLXI  = $(MLXIP)initiate_mlx.c $(MLXIP)sprites.c $(MLXIP)moves.c

PARP  = ./parsing/
PAR   = $(PARP)flood_fill.c $(PARP)main_parser.c $(PARP)parsing.c \
        $(PARP)init_struct.c

PTFP  = ./ft_printf/
PTF   = $(PTFP)ft_printf.c $(PTFP)ft_putchar.c $(PTFP)ft_puthex.c \
        $(PTFP)ft_putnbr.c $(PTFP)ft_putptr.c $(PTFP)ft_putstr.c \
        $(PTFP)ft_putuns.c

GNLP  = ./gnl/
GNL   = $(GNLP)get_next_line.c $(GNLP)get_next_line_utils.c

EXTP  = ./srcs/
EXT   = $(EXTP)ft_split.c $(EXTP)ft_strjoin.c $(EXTP)ft_bzero.c \
        $(EXTP)ft_calloc.c $(EXTP)ft_strlen.c $(EXTP)ft_strdup.c

NAME  = so_long
SRCS  = so_long.c errors.c allocation_handle.c $(PAR) $(GNL) $(PTF) $(EXT) $(MLXI)

OBJS  = $(SRCS:.c=.o)

CC       = cc
CFLAGS   = -Wall -Wextra -Werror -g -Wno-cast-function-type
RM       = rm -f
MLX_ARCH = minilibx-linux/libmlx_Linux.a
MLX_FLAGS = -lXext -lX11

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(MLX_ARCH)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_ARCH) $(MLX_FLAGS) -o $(NAME) && echo "Compiled"

$(MLX_ARCH):
	$(MAKE) -C $(dir $@)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@echo "Cleaned"

re: fclean all

.PHONY: all clean fclean re