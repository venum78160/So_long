/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_utile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:55:57 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/04/07 19:52:28 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open(char *fichier)
{
	int	fd;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("erreur d'ouverture\n", 1);
		exit(1);
	}
	return (fd);
}

int	ft_test(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_del_maps(t_info *info, char *string)
{
	int	i;

	i = 0;
	while (i < info->map.map_height)
		free(info->map.map_s[i++]);
	free(info->map.map_s);
	msg_exit(string);
}

void	m_init(t_info *info, char c, int x, int y)
{
	static int	num_ennemi = 0;

	if (c == 'P')
	{
		info->player.x = x;
		info->player.y = y;
		info->map.map_s[y][x] = '0';
	}
	else if (c == 'D')
	{
		info->ennemi[num_ennemi].x = x;
		info->ennemi[num_ennemi].y = y;
		info->map.map_s[y][x] = '0';
		info->ennemi[num_ennemi].neg = 1;
		num_ennemi++;
	}
}

void	msg_exit(char *string)
{
	ft_putstr_fd(string, 1);
	exit(1);
}
