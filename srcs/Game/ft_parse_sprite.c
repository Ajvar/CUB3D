/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:42:07 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/08 16:40:38 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_sprite_count(t_info *info_map)
{
	int		y;
	int		x;

	y = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (info_map->map[y][x] == '2')
				info_map->sprite_nb++;
			x++;
		}
		y++;
	}
}

void	ft_pos_sprite(t_info *info_map, t_master *master)
{
	int			y;
	int			x;
	int			n;

	y = 0;
	n = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (info_map->map[y][x] == '2')
			{
				master->sprite[n].x = (double)x + 0.5;
				master->sprite[n].y = (double)y + 0.5;
				n++;
			}
			x++;
		}
		y++;
	}
}
