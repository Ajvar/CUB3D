/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_master.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:03:06 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/29 18:01:25 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_master(t_info *info_map, t_mlx *mlx, t_player *player,
t_master *master)
{
	master->save = 0;
	master->info = info_map;
	master->mlx = mlx;
	master->player = player;
	player->pos_x = master->info->player_x + 0.5;
	player->pos_y = master->info->player_y + 0.5;
	ft_res_correction(info_map, mlx);
	if (master->screen_save == 1)
		master->mlx->win = NULL;
}

void	ft_fill_master(t_move *move, t_ray *ray, t_master *master, int save)
{
	master->move = move;
	master->ray = ray;
	master->screen_save = save;
}
