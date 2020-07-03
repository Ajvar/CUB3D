/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:42:14 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/04 17:46:59 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_south_north(t_master *master, int drawstart,
int drawend, int x)
{
	if (master->ray->raydir_y >= 0)
	{
		while (drawstart < drawend)
		{
			*(int *)(&master->mlx->data_img[((drawstart * master->
			mlx->size_line / 4) + x) * master->mlx->bpixel]) = 16724530;
			drawstart++;
		}
	}
	else
	{
		while (drawstart < drawend)
		{
			*(int *)(&master->mlx->data_img[((drawstart * master->
			mlx->size_line / 4) + x) * master->mlx->bpixel]) = 16753920;
			drawstart++;
		}
	}
}

void	ft_draw_east_west(t_master *master, int drawstart,
int drawend, int x)
{
	if (master->ray->raydir_x >= 0)
	{
		while (drawstart < drawend)
		{
			*(int *)(&master->mlx->data_img[((drawstart * master->
			mlx->size_line / 4) + x) * master->mlx->bpixel]) = 3333140;
			drawstart++;
		}
	}
	else
	{
		while (drawstart < drawend)
		{
			*(int *)(&master->mlx->data_img[((drawstart * master->
			mlx->size_line / 4) + x) * master->mlx->bpixel]) = 65535;
			drawstart++;
		}
	}
}

void	ft_draw_wall_color(t_master *master, t_ray *ray, int x)
{
	int		lineheight;
	int		drawstart;
	int		drawend;

	lineheight = (int)(master->info->ry / ray->perpwalldist);
	lineheight *= 1;
	drawstart = -lineheight / 2 + master->info->ry / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + master->info->ry / 2;
	if (drawend >= master->info->ry)
		drawend = master->info->ry - 1;
	if (ray->side == 1)
		ft_draw_south_north(master, drawstart, drawend, x);
	else
		ft_draw_east_west(master, drawstart, drawend, x);
}
