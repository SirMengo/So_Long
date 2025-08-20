/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:52:36 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/20 16:48:20 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	line_length(char *fd)
{
	int length;

	length = 0;
	while(fd[length] != '\0' && fd[length] != '\n')
		length++;
	return (length);
}

static void	initialize(t_map *map, char *aux)
{
	map->player = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->collectible = 0;
	map->exit = 0;
	map->map = ft_split(aux, '\n');
	map->lines = count_lines(map->map);
	map->length = line_length(aux);
	free(aux);
}

int	init_map_struct(int fd, t_map *map)
{
	char	*aux;
	char	*tmp;
	char	*gnl_fd;
	
	gnl_fd = NULL;
	aux = get_next_line(fd);
	while ((gnl_fd = get_next_line(fd)) != NULL)
	{
		tmp = aux;
		if (gnl_fd[0] == '\n')
		{
			free(gnl_fd);
			free(aux);
			close(fd);
			return (0);
		}
		aux = ft_strjoin(aux, gnl_fd);
		free(tmp);
		free(gnl_fd);
	}
	if (!aux)
		return (0);
	initialize(map, aux);
	free(gnl_fd);
	return (1);
}
