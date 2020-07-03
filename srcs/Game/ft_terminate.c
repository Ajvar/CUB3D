/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:24 by jcueille          #+#    #+#             */
/*   Updated: 2020/07/03 17:44:04 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int					ft_exit_prog(t_master *m)
{
	int		y;

	y = 0;
	while (m->info->map[y])
	{
		free(m->info->map[y]);
		y++;
	}
	free(m->info->map[y]);
	free(m->info->map);
	y = 0;
	while (y < 4)
	{
		mlx_destroy_image(m->mlx->ptr, m->texture[y].ptr);
		m->texture[y].ptr = NULL;
		m->texture[y].img = NULL;
		y++;
	}
	//if (m->mlx->img)
	//{
	//	mlx_destroy_image(m->mlx->ptr, m->mlx->img);
		m->mlx->img = NULL;

	//}
	if (m->mlx->win)
	{
		mlx_clear_window(m->mlx->ptr, m->mlx->win);
		mlx_destroy_window(m->mlx->ptr, m->mlx->win);
	}

	free(m->mlx->ptr);

	//free(m->info->south_t);
	exit(0);
	return (1);
}
