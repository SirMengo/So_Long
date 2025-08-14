/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:34:08 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/14 14:22:19 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_consistency(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->lines - 1)
	{
		j = 0;
		while(map->map[i][j] != '\n' || map->map[i][j] != '\0')
			j++;
		if (j != map->length)
			return (0);
		i++;
	}
	return (1);
}
static int	check_borders(char **map, int l, int length)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(map[0][j] != '\n' || map[0][j] || map[l][j] != '\n' || map[l][j])
	{
		if (map[0][j] != '1' ||  map[l][j] != '1')
			return (0);
		j++;
	}
	while(i < l)
	{
		if (map[i][0] != '1' || map[i][length] != '1')
			return (0);
		i++;
	}
	return (1);
}


static int	exists(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while(i < map->lines)
	{
		j = 0;
		while(map->map[i][j])
		{
			if(map->map[i][j] == 'P')
				map->player++;
			if(map->map[i][j] == 'C')
				map->collectible++;
			if(map->map[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	if (map->player != 1 || map->exit != 1)
		return (0);
	if (map->collectible == 0)
		return (0);
	return (1);
}

int	map_parser(t_map *map)
{
	if (check_consistency(map) == 0)
		return (0);
	if (check_borders(map->map, map->lines - 1, map->length) == 0)
		return (0);
	if (exists(map) == 0)
		return (0);
	return (1);
}
