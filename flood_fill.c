/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:57:04 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/19 14:00:46 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cpy(char **map_cpy)
{
	int	i;
	int j;

	i = 0;
	while(map_cpy[i])
	{
		j = 0;
		while (map_cpy[i][j] != '\0' || map_cpy[i][j] == '\n')
		{
			if (map_cpy[i][j] == 'P' || map_cpy[i][j] == 'C' 
				|| map_cpy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

int	locate_player(t_map *map)
{
	char	**map_cpy;
	int		x;
	int		y;

	map_cpy = map->map;
	x = 0;
	y = 0;
	while (map_cpy[y] != NULL)
	{
		x = 0;
		while (map_cpy[y][x] != '\0')
		{
			if (map_cpy[y][x] == 'P')
				flood_fill(map, map_cpy, x, y);
			x++;
		}
		y++;
	}
	if (check_cpy(map_cpy) == 0)
		return (0);
	return (1);
}
