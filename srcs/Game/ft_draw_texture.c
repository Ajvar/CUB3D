/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:42:26 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/04 18:04:58 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_texture_sn(t_master *m, t_texture *texture,
t_text_info *text_i, int x)
{
	if (m->ray->raydir_y >= 0)
	{
		while (text_i->drawstart < text_i->drawend)
		{
			text_i->y = abs((((text_i->drawstart * 256 - m->info->ry * 128
			+ text_i->lineheight * 128) * 64) / text_i->lineheight) / 256);
			ft_memcpy(m->mlx->data_img + 4 * m->info->rx * text_i->drawstart
			+ x * 4, &texture[1].img[text_i->y % 64 * texture[1].size_line +
			text_i->x % 64 * texture[1].bpixel / 8], sizeof(int));
			text_i->drawstart++;
		}
	}
	else
	{
		while (text_i->drawstart < text_i->drawend)
		{
			text_i->y = abs((((text_i->drawstart * 256 - m->info->ry * 128 +
			text_i->lineheight * 128) * 64) / text_i->lineheight) / 256);
			ft_memcpy(m->mlx->data_img + 4 * m->info->rx * text_i->drawstart + x
			* 4, &texture[0].img[text_i->y % 64 * texture[0].size_line +
			text_i->x % 64 * texture[0].bpixel / 8], sizeof(int));
			text_i->drawstart++;
		}
	}
}

void	ft_draw_texture_ew(t_master *m, t_texture *texture,
t_text_info *text_i, int x)
{
	if (m->ray->raydir_x >= 0)
	{
		while (text_i->drawstart < text_i->drawend)
		{
			text_i->y = abs((((text_i->drawstart * 256 - m->info->ry * 128 +
			text_i->lineheight * 128) * 64) / text_i->lineheight) / 256);
			ft_memcpy(m->mlx->data_img + 4 * m->info->rx * text_i->drawstart
			+ x * 4, &texture[3].img[text_i->y % 64 * texture[3].size_line +
			text_i->x % 64 * texture[3].bpixel / 8], sizeof(int));
			text_i->drawstart++;
		}
	}
	else
	{
		while (text_i->drawstart < text_i->drawend)
		{
			text_i->y = abs((((text_i->drawstart * 256 - m->info->ry * 128 +
			text_i->lineheight * 128) * 64) / text_i->lineheight) / 256);
			ft_memcpy(m->mlx->data_img + 4 * m->info->rx * text_i->drawstart
			+ x * 4, &texture[2].img[text_i->y % 64 * texture[2].size_line +
			text_i->x % 64 * texture[2].bpixel / 8], sizeof(int));
			text_i->drawstart++;
		}
	}
}
