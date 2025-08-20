/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:34:42 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/20 19:54:02 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_images(void *mlx, void *win, t_mlx *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map.map[y])
	{
		x = 0;
		while (g->map.map[y][x] != '\0')
		{
			if (g->map.map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, g->wall, x * 64, y * 64);
			else if (g->map.map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, g->ground, x * 64, y * 64);
			else if (g->map.map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, g->player, x * 64, y * 64);
			else if (g->map.map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, g->box, x * 64, y * 64);
			else if (g->map.map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, g->ground, x * 64, y * 64);
			if (g->map.map[y][x] == 'E' && g->map.collectible == 0)
				mlx_put_image_to_window(mlx, win, g->exit, x * 64, y * 64);
			x++;
		}	
		y++;
	}
}

int	destroy_assets(t_mlx *game)
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
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if(game->map.map)
		free_arr(game->map.map);
	exit (EXIT_SUCCESS);
}

int	check_assets(t_mlx *game)
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
	
	game->moves = 0;
	game->ground = mlx_xpm_file_to_image(game->mlx, "sprites/ground.xpm",
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
