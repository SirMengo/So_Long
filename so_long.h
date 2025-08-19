/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:38:49 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/19 16:12:06 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "srcs/srcs.h"
# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct	s_map {
	int		lines;
	int		length;
	int		player;
	int		collectible;
	int		exit;
	char	**map;
}	t_map;

typedef struct	s_mlx {
	void	*mlx;
	void	*mlx_win;
	t_map	map;
}	t_mlx;

//parsing/flood_fill.c
int		locate_player(t_map *map);
//parsing/init_struct.c
int		init_map_struct(int fd, t_map *map);
//parsing/main_parser.c
void	main_parser(t_mlx *game, t_map *map, int fd, char *name);
//parsing/parsing.c
int		map_parser(t_map *map);
//error.c
void	err(int i, char **map, int fd);
//allocation_handling.c
void	free_arr(char **arr);
void	main_allocation_handle(char **map, int fd);

#endif