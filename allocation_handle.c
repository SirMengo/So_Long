/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:17:21 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/19 14:08:08 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

void	main_allocation_handle(char **map, int fd)
{
	free_arr(map);
	close(fd);
}