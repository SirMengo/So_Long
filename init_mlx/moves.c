/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:35:33 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/20 19:53:58 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	finish_game(t_mlx *game, int p_y, int p_x)
{
	int	e_y;
	int	e_x;
	
	e_y = game->map.exit_y;
	e_x = game->map.exit_x;
	game->map.map[e_y][e_x] = 'E';
	if (game->map.map[p_y][p_x] == 'E')
		destroy_assets(game);
}

void	move_player(t_mlx *game, int x, int y)
{
	int	p_y;
	int	p_x;

	p_y = game->map.player_y;
	p_x = game->map.player_x;
	if (game->map.map[p_y + y][p_x + x] == '1')
		return ;
	else
	{
		if (game->map.map[p_y + y][p_x + x] == 'C')
		{
			game->map.collectible--;
			ft_printf("Found %d\n", game->map.collectible);
		}
		game->map.map[p_y + y][p_x + x] = 'P';
		game->map.map[p_y][p_x] = '0';
		game->map.player_x = game->map.player_x + x;
		game->map.player_y = game->map.player_y + y;
		ft_printf("Moves: %d\n", game->moves++);
		if (game->map.collectible == 0)
			finish_game(game, p_y + y, p_x + x);
	}
	draw_images(game->mlx, game->mlx_win, game);
}

int	keys(int key, t_mlx *game)
{
	if (key == XK_Escape)
		destroy_assets(game);
	else if (key == XK_W || key == XK_w)
		move_player(game, 0, -1);
	else if (key == XK_A || key == XK_a)
		move_player(game, -1, 0);
	else if (key == XK_S || key == XK_s)
		move_player(game, 0, 1);
	else if (key == XK_D || key == XK_d)
		move_player(game, 1, 0);

	return (1);
}

