/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimoes <msimoes@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:38:29 by msimoes           #+#    #+#             */
/*   Updated: 2025/08/19 16:02:51 by msimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	/*
	void	*mlx_win;
	void	*image;
	int		width;
	int		height;
	t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 480, 480, "title");
	img.img = mlx_new_image(mlx, 480, 480);
	image = mlx_xpm_file_to_image(mlx, "sprite/Grass.xpm", &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, image, (0 * 64), (0 * 64));
	mlx_destroy_image(mlx, image);
	mlx_loop(mlx);
	
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);*/
	t_map	map;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if(fd < 0)
			err(-1, map.map, fd);
		main_parser(&map, fd, argv[1]);
		main_allocation_handle(map.map, fd);
	}
	else
		write(2, "Error: No map loaded\n", 21);
}
