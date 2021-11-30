/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_aff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:41:04 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/28 18:09:01 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ml_rect(t_info info, t_rect rect, int color)
{
	int	ybis;

	rect.x--;
	while (++rect.x <= rect.m_x)
	{
		ybis = rect.y - 1;
		while (++ybis < rect.m_y)
			my_mlx_pixel_put(&info.st_img, rect.x, ybis, color);
	}
	mlx_put_image_to_window(info.mlx, info.mlx_win, info.st_img.img, 0, 0);
	return ;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

unsigned int	get_mlx_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}
