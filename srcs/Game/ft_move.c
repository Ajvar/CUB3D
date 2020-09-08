/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 15:57:58 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/29 18:23:05 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int ft_hit(char c);

void	ft_move_player_mini_map(t_master *m)
{
	m->player->x = (int)(m->player->pos_x * ((m->info->rx / 3) /
	m->info->len_x));
	m->player->y = (int)(m->player->pos_y * ((m->info->ry / 3) /
	m->info->len_y)) * m->mlx->size_line / 4;
	*(int *)(&m->mlx->data_img[(int)(m->player->x + m->player->y + 1) *
	4]) = 255;
	*(int *)(&m->mlx->data_img[(int)(m->player->x + m->player->y - 1) *
	4]) = 255;
	*(int *)(&m->mlx->data_img[(int)(m->player->x + m->player->y +
	(m->mlx->size_line / 4)) * 4]) = 255;
	*(int *)(&m->mlx->data_img[(int)(m->player->x + m->player->y -
	(m->mlx->size_line / 4)) * 4]) = 255;
}

void	ft_player_pos_x(t_master *m, t_player *p)
{
	if (m->move->left == 1)
	{
		if (ft_hit(m->info->map[(int)(p->pos_y)][(int)(p->pos_x - m->ray->plane_x
		* p->ms)]) == 0)
			p->pos_x = p->pos_x - m->ray->plane_x * p->ms;
		if (ft_hit(m->info->map[(int)(p->pos_y - m->ray->plane_y * p->ms)]
		[(int)(p->pos_x)]) == 0)
			p->pos_y = p->pos_y - m->ray->plane_y * p->ms;
	}
	if (m->move->right == 1)
	{
		if (ft_hit(m->info->map[(int)(p->pos_y)][(int)(p->pos_x + m->ray->plane_x
		* p->ms)]) == 0)
			p->pos_x = p->pos_x + m->ray->plane_x * p->ms;
		if (ft_hit(m->info->map[(int)(p->pos_y + m->ray->plane_y * p->ms)]
		[(int)(p->pos_x)]) == 0)
			p->pos_y = p->pos_y + m->ray->plane_y * p->ms;
	}
}

void	ft_player_pos_dir(t_master *m, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	if (m->move->turn_left == 1)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-p->rot_s) - p->dir_y * sin(-p->rot_s);
		p->dir_y = old_dir_x * sin(-p->rot_s) + p->dir_y * cos(-p->rot_s);
		old_plane_x = m->ray->plane_y;
		m->ray->plane_y = m->ray->plane_y * cos(p->rot_s) - m->ray->plane_x
		* sin(p->rot_s);
		m->ray->plane_x = old_plane_x * sin(p->rot_s) + m->ray->plane_x
		* cos(p->rot_s);
	}
	if (m->move->turn_right == 1)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(p->rot_s) - p->dir_y * sin(p->rot_s);
		p->dir_y = old_dir_x * sin(p->rot_s) + p->dir_y * cos(p->rot_s);
		old_plane_x = m->ray->plane_y;
		m->ray->plane_y = m->ray->plane_y * cos(-p->rot_s) - m->ray->plane_x
		* sin(-p->rot_s);
		m->ray->plane_x = old_plane_x * sin(-p->rot_s) + m->ray->plane_x
		* cos(-p->rot_s);
	}
}

void	ft_player_pos_cam(t_master *m, t_player *p)
{
	if (m->move->foward == 1)
	{
		if (ft_hit(m->info->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x
		* p->ms)]) == 0)
			p->pos_x += p->dir_x * p->ms;
		if (ft_hit(m->info->map[(int)(p->pos_y + p->dir_y * p->ms)]
		[(int)(p->pos_x)]) == 0)
			p->pos_y += p->dir_y * p->ms;
	}
	if (m->move->retreat == 1)
	{
		if (ft_hit(m->info->map[(int)(p->pos_y)][(int)(p->pos_x - p->dir_x
		* p->ms)]) == 0)
			p->pos_x -= p->dir_x * p->ms;
		if (ft_hit(m->info->map[(int)(p->pos_y - p->dir_y * p->ms)]
		[(int)(p->pos_x)]) == 0)
			p->pos_y -= p->dir_y * p->ms;
	}
	ft_player_pos_x(m, p);
	ft_player_pos_dir(m, p);
	if (m->move->sprint == 1)
		p->ms = 0.12;
	if (m->move->sprint == 0)
		p->ms = 0.05;
}

static int ft_hit(char c)
{
	if (c == '1' || c == '2')
		return (1);
	return (0);
}
