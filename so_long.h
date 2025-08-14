/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:38:49 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/14 14:36:49 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "srcs/srcs.h"
# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_map {
	int		lines;
	int		length;
	int		player;
	int		collectible;
	int		exit;
	char	**map;
}	t_map;

void	init_map_struct(int fd, t_map *map);
int		map_parser(t_map *map);
void	err();

#endif