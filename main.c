/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:34:07 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/25 16:52:04 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_info {
	t_data	st_img;
	void	*mlx;
	void	*mlx_win;
}	t_info;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, void * vars)
{
	t_info	*info;
	int		x;
	int		y;

	info = (t_info *) vars;
	printf("salut, voici le key_hook = %i\n", keycode);
	if (keycode == 8)
	{
		x = -1;
		while (++x <= 500)
		{
			y = 449;
			while (++y <= 500)
				my_mlx_pixel_put(&info->st_img, x, y, 0x0000ff00);
		}
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->st_img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_info	ml;
	int		x;
	int		y;

	x = -1;
	ml.mlx = mlx_init();
	ml.mlx_win = mlx_new_window(ml.mlx, 500, 500, "Hello world!");
	ml.st_img.img = mlx_new_image(ml.mlx, 500, 500);
	ml.st_img.addr = mlx_get_data_addr(ml.st_img.img, &ml.st_img.bits_per_pixel, &ml.st_img.line_length,
								&ml.st_img.endian);
	while (++x <= 500)
	{
		y = -1;
		while (++y <= 50)
			my_mlx_pixel_put(&ml.st_img, x, y, 0x00FF0000);
	}
	mlx_put_image_to_window(ml.mlx, ml.mlx_win, ml.st_img.img, 0, 0);
	x = -1;
	while (++x <= 500)
	{
		y = 449;
		while (++y <= 500)
			my_mlx_pixel_put(&ml.st_img, x, y, 0x000000FF);
	}
	mlx_put_image_to_window(ml.mlx, ml.mlx_win, ml.st_img.img, 0, 0);
	mlx_key_hook(ml.mlx_win, key_hook, &ml);
	printf("salut\n");
	mlx_loop(ml.mlx);
}