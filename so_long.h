/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:26:08 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/30 19:26:46 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

//structure


typedef struct s_map
{
	int		map_width;
	int		map_height;
	int		numb_move;
	// t_img	*ground;
	// t_img	*player;
	// t_img	*collectible;
	// t_img	*tree;
	// t_img	*exit;
	char	**map_s;
	int		collectible;
	int		exit;
	int		player;
	int		nbr_ennemi;
}	t_map;

typedef struct s_player {
	int		x;
	int		y;
}	t_player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_rect {
	int	x;
	int	m_x;
	int	y;
	int	m_y;
}	t_rect;

typedef struct s_info {
	t_data			st_img;
	void			*mlx;
	void			*mlx_win;
	unsigned int	color;
	t_player		player;
	t_player		*ennemi;
	t_map			map;
	int				pixel_x;
	int				pixel_y;
}	t_info;

//prototype

unsigned int	get_mlx_pixel(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				key_hook(int keycode, void *vars);
//void			ml_rect(t_info info, int x, int m_x,int y, int m_y, int color);
void			ml_rect(t_info info, t_rect rect, int color);
int				render(t_info *ml);
//int				etoile(t_info *ml);
int				move_up(t_info *info);
int				move_down(t_info *info);
int				move_left(t_info *info);
// int				move_right(t_info *info);
void			make_tab(t_info *info);
int				ft_open(char *fichier);
int				m_test_rect(char *fichier, int comp);
void			m_verif_map(t_info *info, char *fichier, int comp);
int				ft_test(char c, char *sep);
void			m_verif_cat(t_info *info, char *ligne, int comp, int fd);
void			verif_pec(t_info info);
void			m_ft_ferme(t_info info);
void			ft_del_maps(t_info *info, char *string);
void			m_init(t_info *info, char c, int x, int y);
void			m_nbr_ennemi(t_info *info);
void			ml_case(t_info *info);
void			ml_determ_case(int x, int y/*,t_info *info*/);

#endif