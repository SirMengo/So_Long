/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:36:43 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/19 14:17:56 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err(int i, char **map, int fd)
{
	if (i == 0)
	{
		write (2, "Error: Failed initiating map\n", 29);
		close(fd);
		exit(EXIT_FAILURE);
	}
	else if (i == -1)
		write (2, "Error: Failed to open fd\n", 25);
	else if (i == 1)
		write (2, "Error: Inconsistent map border\n", 31);
	else if (i == 2)
		write (2, "Error: Invalid number of characters in map\n", 43);
	else if (i == 3)
		write (2, "Error: Forbidden character found\n", 33);
	else if (i == 4)
		write (2, "Error: Unbeatable map\n", 22);
	main_allocation_handle(map, fd);
	exit (EXIT_FAILURE);
}