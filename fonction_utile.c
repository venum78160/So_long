/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_utile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:55:57 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/30 18:30:38 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open(char *fichier)
{
	int	fd;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
	{
		printf("erreur d'ouverture\n");
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
	int i;
	
	i = 0;
	while(info->map.map_s[i])
		free(info->map.map_s[i++]);
	free(info->map.map_s);
	printf("%s\n", string);
	exit(1);
}

void	m_init(t_info *info, char c, int x, int y)
{
	static int	num_ennemi = 0;

	if(c == 'P')
	{
		info->player.x = x;
		info->player.y = y;
		printf("player = %i,%i\n", info->player.x, info->player.y);
	}
	else if (c == 'D')
	{
		info->ennemi[num_ennemi].x = x;
		info->ennemi[num_ennemi].y = y;
		printf("ennemi%i = %i,%i\n", num_ennemi, info->ennemi[num_ennemi].x, info->ennemi[num_ennemi].y);
		num_ennemi++;
	}
}