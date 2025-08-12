/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:34:08 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/12 16:25:52 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_consistency(char *fd, int len, int lines)
{
	int	i;
	int	current;
	
	i = 0;
	while(fd[i] != '\0')
	{
		if(fd[i] == '\n')
		{
			if(current != len)
				return (0);
			current = 0;
		}
		i++;
		current++;
	}
	return (1);
}

int	get_sizes(char *fd)
{
	int i;
	int	len;
	int	lines;

	len = 0;
	while(fd[len] != '\n' || fd[len] == '\0')
		len++;
	lines = 0;
	i = 0;
	while(fd[i] != '\0')
	{
		if(fd[i] == '\n')
			lines++;
		i++;
	}
	if(line_consistency(fd, len, lines) == 1)
		return (1);
	return (0);
}

int	map_parser(char *fd)
{
	if(get_sizes(fd) == 1)
		
}