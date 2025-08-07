# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 12:46:46 by msimoes           #+#    #+#              #
#    Updated: 2025/08/07 11:08:38 by msimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c

COMP_LIB = ar rcs
RM = rm -f
CC = cc
CC_FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = minilibx-linux/libmlx_Linux.a -lXext -lX11

OBJS = $(SRCS:.c=.o)

%.o : %.c
	@ $(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(EXT_PATH) $(OBJS_EXT)
	@ $(CC) $(CC_FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) | echo "Compiled"

all: $(NAME)

clean:
	@ $(RM) $(OBJS) $(EXT_PATH)$(OBJS_EXT)

fclean: clean
	@ $(RM) $(NAME) $(EXT_PATH)$(OBJS_EXT) | echo "Cleaned"

re: fclean all

.PHONY: all clean fclean re