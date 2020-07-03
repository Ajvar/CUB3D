/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 14:33:55 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/08 16:40:03 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_sidedist(t_ray *ray, t_master *master)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (master->player->pos_x - ray->map_x)
		* ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - master->player->pos_x)
		* ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (master->player->pos_y - ray->map_y)
		* ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - master->player->pos_y)
		* ray->deltadist_y;
	}
}

void	ft_dda(t_ray *ray, t_master *master, int x)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (master->info->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->map_x - master->player->pos_x +
		(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = (ray->map_y - master->player->pos_y +
		(1 - ray->step_y) / 2) / ray->raydir_y;
	master->zbuffer[x] = ray->perpwalldist;
}

void	ft_raycaster(t_master *master, t_ray *ray)
{
	int		x;

	x = 0;
	master->zbuffer = malloc(sizeof(double) * master->info->rx);
	while (x < master->info->rx)
	{
		ray->cam_x = 2 * x / (double)master->info->rx - 1;
		ray->raydir_x = master->player->dir_x + ray->plane_x * ray->cam_x;
		ray->raydir_y = master->player->dir_y + ray->plane_y * ray->cam_x;
		ray->map_x = (int)master->player->pos_x;
		ray->map_y = (int)master->player->pos_y;
		ray->deltadist_x = fabs(1 / ray->raydir_x);
		ray->deltadist_y = fabs(1 / ray->raydir_y);
		ft_sidedist(ray, master);
		ft_dda(ray, master, x);
		if (master->move->texture == 0)
			ft_draw_wall_color(master, ray, x);
		else
			ft_texture(master, ray, x);
		ray->hit = 0;
		x++;
	}
}
