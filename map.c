/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:34:57 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/12/08 16:09:18 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_tab(t_info *i)
{
	int		fd;
	int		comp;
	int		n;

	comp = 0;
	n = -1;
	fd = ft_open(i->map.name_fichier);
	while (get_next_line(fd) != NULL)
		comp++;
	i->map.map_height = comp;
	close(fd);
	i->map.map_width = m_test_rect(i->map.name_fichier, comp);
	m_verif_map(i, i->map.name_fichier, comp);
	fd = open(i->map.name_fichier, O_RDONLY);
	i->map.map_s = calloc(sizeof(char *), (i->map.map_height + 1));
	while (--comp >= 0)
		i->map.map_s[++n] = get_next_line(fd);
	m_nbr_ennemi(i);
	m_ft_ferme(i);
	return ;
}

void	m_nbr_ennemi(t_info *i)
{
	int	n;
	int	j;

	n = -1;
	i->map.nbr_ennemi = 0;
	while (++n < i->map.map_height)
	{
		j = -1;
		while (++j < i->map.map_width)
		{
			if (i->map.map_s[n][j] == 'D')
				i->map.nbr_ennemi++;
		}
	}
	i->ennemi = calloc(sizeof(t_player), i->map.nbr_ennemi);
}
