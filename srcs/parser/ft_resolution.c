/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:00:11 by jcueille          #+#    #+#             */
/*   Updated: 2020/09/08 18:00:14 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_resolution(char *s, t_info *info_map)
{
	int		i;

	i = 2;
	ft_space_skip(s, &i);
	if (info_map->rx > 0 || info_map->rx > 0)
		ft_error("Resolution specified two times.");
	info_map->rx = ft_atoi(&s[i]);
	while (s[i] && s[i] != ' ')
		i++;
	ft_space_skip(s, &i);
	if ((s[i] > '9' && s[i] < '0') || s[i] == '\0')
		ft_error("resolution needs two numbers");
	info_map->ry = ft_atoi(&s[i]);
	if (info_map->rx < 1 || info_map->ry < 1)
		ft_error("resolution can't be under 1");
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	ft_space_skip(s, &i);
	if (s[i] != '\0')
		ft_error("wrong char at the end of resolution");
	return (1);
}

void		ft_res_correction(t_info *map, t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_get_screen_size(mlx->ptr, &x, &y);
	if (map->rx > x)
		map->rx = x;
	if (map->ry > y)
		map->ry = y;
}
