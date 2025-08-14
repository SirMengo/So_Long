# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 12:46:46 by msimoes           #+#    #+#              #
#    Updated: 2025/08/14 14:49:10 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNLP = ./gnl/
GNL = $(GNLP)get_next_line.c $(GNLP)get_next_line_utils.c

EXTP = ./srcs/
EXT = $(EXTP)ft_split.c $(EXTP)ft_strjoin.c $(EXTP)ft_bzero.c \
		$(EXTP)ft_calloc.c $(EXTP)ft_strlen.c

NAME = so_long
SRCS = so_long.c parsing.c init_struct.c errors.c $(GNL) $(EXT)

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