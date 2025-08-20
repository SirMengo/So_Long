/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:38:29 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/20 22:31:36 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int				fd;
	static t_map	map;
	static t_mlx	game;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			err(-1, map.map, fd);
		map.fd = fd;
		main_parser(&game, &map, fd, argv[1]);
		init_game(&game);
		main_allocation_handle(map.map, map.fd);
	}
	else
		write (2, "Error: No map loaded\n", 21);
}
