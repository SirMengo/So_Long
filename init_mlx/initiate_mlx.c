/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:21:44 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/20 16:40:08 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_mlx *game)
{
	if (game->map.map && game->map.lines > 0 && game->map.length > 0)
	{
		game->mlx = mlx_init();
		init_assets(game);
		game->mlx_win = mlx_new_window(game->mlx, game->map.length * 64,
			game->map.lines * 64, "So_Long");
		if (check_assets(game) == 0)
		{
			destroy_assets(game);
			write(2, "Error: Asset failed to initialize\n", 34);
			exit (EXIT_FAILURE);
		}
		draw_images(game->mlx, game->mlx_win, game);
		mlx_hook(game->mlx_win, 17, 0, destroy_assets, game);
		mlx_hook(game->mlx_win, KeyPress, KeyPressMask, keys, game);
		mlx_loop(game->mlx);
	}
}
