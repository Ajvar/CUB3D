/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:34 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/29 17:31:49 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_sprite_texture(t_master *m, t_sprite_info *s_i)
{
	int	stripe;
	int	y;

	stripe = s_i->drawstart_x;
	while (stripe < s_i->drawend_x + 1)
	{
		s_i->texx = (int)((256 * (stripe - (-s_i->width / 2 + s_i->screen_x))
		* s_i->texwidth / s_i->width) / 256);
		y = s_i->drawstart_y;
		while (y < s_i->drawend_y && s_i->transformy > 0 && s_i->transformy
		< m->zbuffer[stripe])
		{
			s_i->d = y * 256 - m->info->ry * 128 + s_i->height * 128;
			s_i->texy = ((s_i->d * s_i->texheight) / s_i->height) / 256;
			if (m->texture[4].img[s_i->texy % 64 * m->texture[4].size_line
			+ s_i->texx % 64 * m->texture[4].bpixel / 8] != 0)
			{
				ft_memcpy(m->mlx->data_img + 4 * m->info->rx * y + stripe * 4,
				&m->texture[4].img[s_i->texy % 64 * m->texture[4].size_line +
				s_i->texx % 64 * m->texture[4].bpixel / 8], sizeof(int));
			}
			y++;
		}
		stripe++;
	}
}

void	ft_draw_sprite(t_sprite_info *s_i, t_sprite *sprite, int *sprite_order,
t_master *m)
{
	s_i->x = sprite[sprite_order[s_i->i]].x - m->player->pos_x;
	s_i->y = sprite[sprite_order[s_i->i]].y - m->player->pos_y;
	s_i->inv_det = 1.0 / (m->ray->plane_x * m->player->dir_y -
	m->player->dir_x * m->ray->plane_y);
	s_i->transformx = s_i->inv_det * (m->player->dir_y * s_i->x -
	m->player->dir_x * s_i->y);
	s_i->transformy = s_i->inv_det * (-m->ray->plane_y * s_i->x +
	m->ray->plane_x * s_i->y);
	s_i->screen_x = (int)((m->info->rx / 2) * (1 + s_i->transformx /
	s_i->transformy));
	s_i->height = abs((int)(m->info->ry / (s_i->transformy)));
	s_i->drawstart_y = -s_i->height / 2 + m->info->ry / 2;
	if (s_i->drawstart_y < 0)
		s_i->drawstart_y = 0;
	s_i->drawend_y = s_i->height / 2 + m->info->ry / 2;
	if (s_i->drawend_y >= m->info->ry)
		s_i->drawend_y = m->info->ry - 1;
	s_i->width = abs((int)(m->info->ry / (s_i->transformy)));
	s_i->drawstart_x = -s_i->width / 2 + s_i->screen_x;
	if (s_i->drawstart_x < 0)
		s_i->drawstart_x = 0;
	s_i->drawend_x = s_i->width / 2 + s_i->screen_x;
	if (s_i->drawend_x >= m->info->rx)
		s_i->drawend_x = m->info->rx - 1;
}

void	ft_sort_sprites(int *sprite_order, double *sprite_distance,
int sprite_nb)
{
	int		i;
	int		tmp_order;
	double	tmp_dist;

	i = 0;
	while (i < sprite_nb - 1)
	{
		if (sprite_distance[i] > sprite_distance[i + 1])
		{
			tmp_dist = sprite_distance[i];
			sprite_distance[i] = sprite_distance[i + 1];
			sprite_distance[i + 1] = tmp_dist;
			tmp_order = sprite_order[i];
			sprite_order[i] = sprite_order[i + 1];
			sprite_order[i + 1] = tmp_order;
			i = -1;
		}
		i++;
	}
}

void	ft_init_sprite(t_master *m, t_sprite *sprite, int *sprite_order,
double *sprite_distance)
{
	int		i;

	i = 0;
	while (i < m->info->sprite_nb)
	{
		sprite_distance[i] = ((m->player->pos_x - sprite[i].x) *
		(m->player->pos_x - sprite[i].x) + (m->player->pos_y - sprite[i].y)
		* (m->player->pos_y - sprite[i].y));
		sprite_order[i] = i;
		i++;
	}
	ft_sort_sprites(sprite_order, sprite_distance, m->info->sprite_nb);
}

void	ft_sprite(t_master *m, t_sprite *sprite, int sprite_nb)
{
	int					sprite_order[sprite_nb];
	double				sprite_distance[sprite_nb];
	t_sprite_info		s_i;

	ft_init_sprite(m, sprite, sprite_order, sprite_distance);
	s_i.texwidth = 64;
	s_i.texheight = 64;
	s_i.i = sprite_nb - 1;
	while (s_i.i >= 0)
	{
		ft_draw_sprite(&s_i, sprite, sprite_order, m);
		ft_sprite_texture(m, &s_i);
		s_i.i--;
	}
}
