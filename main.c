/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:34:07 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/29 11:59:08 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *vars)
{
	t_info	*info;

	info = (t_info *) vars;
	printf("salut, voici le key_hook = %i\n", keycode);
	if (keycode == 0)
		move_left(info);
	if (keycode == 1)
		move_down(info);
	if (keycode == 2)
		//move_right(info);
	if (keycode == 13)
		move_up(info);
	if (keycode == 53)
	{
		mlx_destroy_window(info->mlx, info->mlx_win);
		exit(0);
	}
	return (0);
}

int	main()
{
	t_info	ml;
	
	make_tab(&ml);
	ml.color = 0;
	ml.player.x = 200;
	ml.player.y = 200;
	ml.mlx = mlx_init();
	ml.mlx_win = mlx_new_window(ml.mlx, 700, 700, "Hello world!");
	ml.st_img.img = mlx_new_image(ml.mlx, 700, 700);
	ml.st_img.addr = mlx_get_data_addr(ml.st_img.img, &ml.st_img.bits_per_pixel, &ml.st_img.line_length,
								&ml.st_img.endian);
	printf("salut\n");
	mlx_string_put(ml.mlx, ml.mlx_win, 200, 200, 0x00FFFFFF, "salut");
	mlx_key_hook(ml.mlx_win, key_hook, &ml);
	mlx_loop_hook(ml.mlx, render, &ml);
	mlx_loop(ml.mlx);
	return (0);
}