/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:50:26 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/20 20:05:56 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	locate_exit(t_map *map)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			if (map->map[y][x] == 'E')
			{
				map->exit_x = x;
				map->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

void	main_parser(t_mlx *game, t_map *map, int fd, char *name)
{
	int	error_code;
	int		len;
	
	len = ft_strlen(name) - 1;
	if (len - 4 <= 4)
	{
		write(2, "Error: Invalid file format\n", 27);
		exit(EXIT_FAILURE);
	}
	if (name[len] != 'r' || name[len - 1] != 'e' || name[len - 2] != 'b'
		|| name[len - 3] != '.')
	{
		write(2, "Error: Invalid file format\n", 27);
		exit(EXIT_FAILURE);
	}
	error_code = 0;
	if (init_map_struct(fd, map) == 0)
		err(0, map->map, fd);
	error_code = map_parser(map);
	if (error_code != (0))
		err(error_code, map->map, fd);
	if (locate_player(map) == 0)
		err(4, map->map, fd);
	locate_exit(map);
	game->map = *map;
}
