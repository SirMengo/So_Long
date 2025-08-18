/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:57:04 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/18 14:48:06 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_cpy(char **map_cpy)
{
	printf("%s", map_cpy[0]);
	printf("%s", map_cpy[1]);
	printf("%s", map_cpy[2]);
	printf("%s", map_cpy[3]);
	printf("%s", map_cpy[4]);

}

void	flood_fill(t_map *map, char **map_cpy, int x, int y)
{
	if (y < 0 || y >= map->lines || x < 0 || x >= map->length)
		return ;
	if (!(map_cpy[y][x] == 'P' || map_cpy[y][x] == 'E' || map_cpy[y][x] == 'C' 
		|| map_cpy[y][x] == '0'))
		return ;
	map_cpy[y][x] = 'F';
	flood_fill(map, map_cpy, x, y + 1);
	flood_fill(map, map_cpy, x, y - 1);
	flood_fill(map, map_cpy, x + 1, y);
	flood_fill(map, map_cpy, x - 1, y);
}

void	locate_player(t_map *map)
{
	char	**map_cpy;
	int		x;
	int		y;

	map_cpy = map->map;
	x = 0;
	y = 0;
	while (map_cpy[y][x])
	{
		y++;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == 'P')
				flood_fill(map, map_cpy, x, y);
			x++;
		}
		x = 0;
	}
	check_cpy(map_cpy);
}
