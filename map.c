/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:34:57 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/30 17:45:33 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_tab(t_info *info)
{
	int		fd;
	int		comp;
	int		n;

	comp = 0;
	n = -1;
	fd = ft_open("maps.ber");
	while (get_next_line(fd) != NULL)
		comp++;
	info->map.map_height = comp;
	close(fd);
	info->map.map_width = m_test_rect("maps.ber", comp);
	m_verif_map(info, "maps.ber", comp);
	fd = open("maps.ber", O_RDONLY);
	info->map.map_s = calloc(1, (info->map.map_height + 1));
	while (--comp >= 0)
	{
		info->map.map_s[++n] = calloc(1, (info->map.map_width + 1));
		info->map.map_s[n] = get_next_line(fd);
		printf("valeur maps %i = %s\n", n, info->map.map_s[n]);
	}
	m_nbr_ennemi(info);
	m_ft_ferme(*info);
	printf("fin\n");
	return ;
}

void	m_nbr_ennemi(t_info *info)
{
	int	n;
	int	i;

	n = -1;
	info->map.nbr_ennemi = 0;
	while (++n < info->map.map_height)
	{
		i = -1;
		while (++i < info->map.map_width)
		{
			if (info->map.map_s[n][i] == 'D')
				info->map.nbr_ennemi++;
		}
	}
	info->ennemi = calloc(sizeof(t_player), info->map.nbr_ennemi);
	printf("nbr_ennemi = %i\n", info->map.nbr_ennemi);
}
