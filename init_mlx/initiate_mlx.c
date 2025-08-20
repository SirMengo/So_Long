/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:21:44 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/20 13:15:30 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_images(void *mlx, void *win, t_mlx *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map.map[y] != NULL)
	{
		x = 0;
		while (g->map.map[y][x] != '\0' || g->map.map[y][x] != '\n')
		{
			if (g->map.map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, g->wall, (y * 64), (x * 64));
			else if (g->map.map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, g->ground,
					(y * 64), (x * 64));
			else if (g->map.map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, g->player, (y * 64),
					(x * 64));
			else if (g->map.map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, g->box, (y * 64), (x * 64));
			else if (g->map.map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, g->exit, (y * 64), (x * 64));
			x++;
		}
		y++;
	}
}

void	destroy_assets(t_mlx *game)
{
	if (game->ground)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->box)
		mlx_destroy_image(game->mlx, game->box);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

int check_assets(t_mlx *game)
{
	if (!game->ground)
		return (0);
	if (!game->player)
		return (0);
	if (!game->box)
		return (0);
	if (!game->wall)
		return (0);
	if (!game->exit)
		return (0);
	return (1);
}

void	init_assets(t_mlx *game)
{
	int	width;
	int	height;

	game->ground = mlx_xpm_file_to_image(game->mlx, "sprite/ground.xpm",
		&width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm",
		&width, &height);
	game->box = mlx_xpm_file_to_image(game->mlx, "sprites/box.xpm",
		&width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
		&width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
		&width, &height);
}

void	init_game(t_mlx *game)
{
	if (game->map.map && game->map.lines > 0 && game->map.length > 0)
	{
		printf("%d\n", game->map.length);
		printf("%d", game->map.lines);
		game->mlx = mlx_init();
		game->mlx_win = mlx_new_window(game->mlx, game->map.length * 64,
			game->map.lines * 64, "So_Long");
		//init_assets(game);
		//Seg fault on close on X
		/*if (check_assets(game) == 0)
		{
			destroy_assets(game);
			write(2, "Error: Asset failed to initialize\n", 34);
			exit (EXIT_FAILURE);
		}
		draw_images(game->mlx, game->mlx_win, game);*/
		//mlx_hook(game->mlx_win, 17, 0, mlx_destroy_window, game->mlx_win);
		mlx_loop(game->mlx);
	}
}
