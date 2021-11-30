/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:49:54 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/30 19:35:12 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_info *ml)
{
	ml_rect(*ml, (t_rect){0, 700, 0, 126}, ml->color);
	ml_rect(*ml, (t_rect){0, 700, 574, 700}, ml->color);
	ml->color += 1;
	ml_rect(*ml, (t_rect){200, 201, 200, 201}, 0x00FFFFFF);
	ml_case(ml);
	//mlx_string_put(ml->mlx, ml->mlx_win, 200, 200, 0x00FFFFFF, "salut");
	return (0);
}

void	ml_case(t_info *info)
{
	int	x;
	int	y;
	(void)info;
	// int	ind_x;
	// int	ind_y;


	y = 126;
	while (y < 574)
	{
		x = 126;
		while (x < 574)
		{
			printf("x %i, y %i\n", x, y);
			ml_determ_case(x ,y);
			x += 64;
		}
		exit(1);
		y += 64;
	}
	printf("fin de la fonction\n");
}

void	ml_determ_case(int x, int y/*,t_info *info*/)
{	
	x = (x - 126) / 64;
	y = (y - 126) / 64;
	printf("x = %i, y = %i\n", x, y);
}
// int	etoile(t_info *ml)
// {
// 	printf("test\n");
// 	ml_rect(*ml, 0, 700, 0, 126, ml->color);
// 	ml_rect(*ml, 0, 700, 574, 700, ml->color);
// 	printf("test++\n");
// 	ml->color = (ml->color + 1) * (ml->color + 1) % 0x00FFFFFF;
// 	printf("test333333\n");
// 	return (0);
// }
