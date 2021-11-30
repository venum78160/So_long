/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:17:49 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/30 18:57:08 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	m_test_rect(char *fichier, int comp)
{
	size_t	x;
	int		fd;

	fd = ft_open(fichier);
	x = ft_strlen(get_next_line(fd));
	while (--comp >= 1)
	{
		if (ft_strlen(get_next_line(fd)) != x)
		{
			printf("la map : %s n'est pas une map rectangulaire\n", fichier);
			exit(1);
		}
	}
	close(fd);
	return (x);
}

void	m_verif_cat(t_info *info, char *ligne, int comp, int fd)
{
	int	i;

	while (--comp >= 0)
	{
		ligne = get_next_line(fd);
		i = -1;
		while (ligne[++i])
		{
			if (ligne[i] == 'C')
				info->map.collectible++;
			else if (ligne[i] == 'P')
				info->map.player++;
			else if (ligne[i] == 'E')
				info->map.exit++;
			else if (ft_test(ligne[i], "01CPED") == 0)
			{
				printf("Mauvais caractere sur la carte\n");
				free(ligne);
				exit(1);
			}
		}
	}
	close(fd);
}

void	m_verif_pec(t_info info)
{
	if (info.map.collectible < 1)
	{
		printf("pas assez de collectible\n");
		exit(1);
	}
	if (info.map.exit < 1)
	{
		printf("pas assez d'exit\n");
		exit(1);
	}
	if (info.map.player != 1)
	{
		printf("pas le bon nombre de player\n");
		exit(1);
	}
}

void	m_verif_map(t_info *info, char *fichier, int comp)
{
	int		fd;
	char	*ligne;

	fd = ft_open(fichier);
	ligne = calloc(1, info->map.map_width + 1);
	m_verif_cat(info, ligne, comp, fd);
	m_verif_pec(*info);
}

void	m_ft_ferme(t_info info)
{
	int	n;
	int	i;

	n = -1;
	while (++n < info.map.map_height)
	{
		if (info.map.map_s[n][0] != '1' || info.map.map_s[n][info.map.map_width - 1] != '1')
			ft_del_maps(&info, "mauvaise bordure");
		i = -1;
		while (++i < info.map.map_width)
		{
			if (n == 0 && (info.map.map_s[n][i] != '1'))
				ft_del_maps(&info, "ligne 1 pas que des 1");
			else if (n == info.map.map_height - 1 && info.map.map_s[n][i] != '1')
				ft_del_maps(&info, "derniere ligne pas que des 1");
			m_init(&info, info.map.map_s[n][i], i, n);
		}
	}
}
