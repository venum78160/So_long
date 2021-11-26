/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:26:08 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/26 11:29:52 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
#include <mlx.h>
#include <stdio.h>

//prototype 

int	ft_display_c(va_list args, int n);
int	ft_display_int(va_list args, int fd);
int	ft_display_p(va_list args);
int	ft_display_s(va_list args, int n);
int	ft_display_u(va_list args, int fd);
int	ft_display_x(va_list args);
int	ft_display_xmaj(va_list args);
int	ft_printf(const char *string, ...);
int	ft_display_pourc(char args, int n);

#endif