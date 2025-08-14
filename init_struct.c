/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:52:36 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/13 15:28:35 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int *fd)
{
	int	i;
	int	lines;
	
	i = 0;
	lines = 0;
	while (fd[i] != '\0')
	{
		if(fd[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

int	line_length(char *fd)
{
	int length;

	length = 0;
	while(fd[length] != '\0' || fd[length] != '\n')
		length++;
	return (length);
}

void	init_map_struct(int *fd, t_map *map)
{
	char *aux;
	
	map->lines = count_lines(fd);
	map->length = line_length(fd);
	while ((fd = get_next_line(fd)) != NULL)
	{
		aux = fd;
		free(fd);	
	}
	map->map = ft_split(aux, '\n');
}