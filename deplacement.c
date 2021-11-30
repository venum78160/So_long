/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:04:14 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/28 18:04:06 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_down(t_info *info)
{
	int	y;
	int	x;

	y = info->player.y;
	x = info->player.x;
	ml_rect(*info, (t_rect){x, x + 64, y, y + 64}, 0x000000FF);
	ml_rect(*info, (t_rect){x, x + 64, y - 64, y}, 0x00000000);
	printf("infoplayer-- = %i\n", info->player.y);
	info->player.y = y + 64;
	printf("infoplayer++ = %i\n", info->player.y);
	return (1);
}

int	move_up(t_info *info)
{
	int	y;
	int	x;

	y = info->player.y;
	x = info->player.x;
	ml_rect(*info, (t_rect){x, x + 64, y, y + 64}, 0x000000FF);
	ml_rect(*info, (t_rect){x, x + 64, y + 64, y + 128}, 0x00000000);
	info->player.y = y - 64;
	return (1);
}

int	move_left(t_info *info)
{
	int	y;
	int	x;

	y = info->player.y;
	x = info->player.x;
	ml_rect(*info, (t_rect){x, x + 64, y, y + 64}, 0x000000FF);
	ml_rect(*info, (t_rect){x, x + 64, y - 64, y}, 0x00000000);
	info->player.y = y - 64;
	return (1);
}

// int	move_right(t_info *info)
// {
// 	int	xdest;
// 	int	y;
// 	int	x;

// 	y = info->player.y;
// 	x = info->player.x;
// 	xdest = info->player.x;
// 	while (x < xdest + 64)
// 	{
// 		ml_rect(*info, x, x + 64, y, y + 64, 0x000000FF);
// 		ml_rect(*info, x, x - 1, y, y + 64, 0x00000000);
// 		x++;
// 	}
// 	printf("infoplayer-- = %i\n", info->player.x);
// 	info->player.x = x;
// 	printf("infoplayer++ = %i\n", info->player.x);
// 	return (1);
// }
