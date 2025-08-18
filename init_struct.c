/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:52:36 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/18 15:22:48 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	line_length(char *fd)
{
	int length;

	length = 0;
	while(fd[length] != '\0' && fd[length] != '\n')
		length++;
	return (length);
}

void	init_map_struct(int fd, t_map *map)
{
	char	*aux;
	char	*gnl_fd;
	int		i;
	
	gnl_fd = NULL;
	map->player = 0;
	map->collectible = 0;
	map->exit = 0;
	aux = get_next_line(fd);
	while ((gnl_fd = get_next_line(fd)) != NULL)
	{
		aux = ft_strjoin(aux, gnl_fd);
		free(gnl_fd);
	}
	close(fd);
	map->map = ft_split(aux, '\n');
	map->lines = count_lines(map->map);
	map->length = line_length(aux);
	i = 0;
	while (i < map->lines)
	{
		if (!map->map[i] || map->map[i][0] == '\0')
		{
			err();
			exit (EXIT_FAILURE);
		}
		i++;
	}
}
