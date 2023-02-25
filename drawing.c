/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctardy <ctardy@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:36:26 by ctardy            #+#    #+#             */
/*   Updated: 2023/02/25 13:46:25 by ctardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw(t_data img, int x, int draw_start, int draw_end, int color)
{
	printf("Value de start %d et end %d de color %d\n", draw_start, draw_end, color);
	while (draw_start < draw_end)
	{
		my_mlx_pixel_put(&img, x, draw_start++, color);
	}
}
	// // S
	// printf("couleur atm %d\n", img.flag);
	// draw(i, iend, j, jstart, jend, img, color);
	// draw(i, iend - 75, j + 25, jstart + 25, jend + 50, img, color);
	// draw(i, iend, j + 75, jstart, jend + 75, img, color);
	// draw(i + 75, iend, j + 100, jstart + 100, jend + 150, img, color);
	// draw(i, iend, j + 150, jstart + 150, jend + 150, img, color);



// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1024, 720, "Siuu");
// 	img.flag = 1;
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	print_siuu(img);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_hook(mlx_win, 2, (1L << 0), print_siuu, &img);
// 	mlx_loop(mlx);
// }
