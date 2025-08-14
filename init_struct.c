/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:52:36 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/14 15:56:21 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *fd)
{
	int	i;
	int	lines;
	
	i = 0;
	lines = 0;
	while (fd[i] != '\0')
	{
		if(fd[i] == '\n' || fd[i + 1] == '\0')
			lines++;
		i++;
	}
	return (lines);
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
	char *aux;
	char *gnl_fd;
	
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
	map->lines = count_lines(aux);
	map->length = line_length(aux);
	map->map = ft_split(aux, '\n');
}