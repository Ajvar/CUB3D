/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:37:42 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/08 16:37:44 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_init_texture_data(t_texture *texture, t_master *m)
{
	texture[0].img = mlx_get_data_addr(texture[0].ptr, &texture[0].bpixel,
	&texture[0].size_line, &texture[0].endian);
	if (texture[0].img == NULL)
		ft_error_free("bad texture north", m->info);
	texture[1].img = mlx_get_data_addr(texture[1].ptr, &texture[1].bpixel,
	&texture[1].size_line, &texture[1].endian);
	if (texture[1].img == NULL)
		ft_error_free("bad texture south", m->info);
	texture[2].img = mlx_get_data_addr(texture[2].ptr, &texture[2].bpixel,
	&texture[2].size_line, &texture[2].endian);
	if (texture[2].img == NULL)
		ft_error_free("bad texture west", m->info);
	texture[3].img = mlx_get_data_addr(texture[3].ptr, &texture[3].bpixel,
	&texture[3].size_line, &texture[3].endian);
	if (texture[3].img == NULL)
		ft_error_free("bad texture east", m->info);
	texture[4].img = mlx_get_data_addr(texture[4].ptr, &texture[4].bpixel,
	&texture[4].size_line, &texture[4].endian);
	if (texture[4].img == NULL)
		ft_error_free("bad sprite texture", m->info);
	return (1);
}

int		ft_init_texture(t_master *m, t_texture *texture, int w,
int h)
{
	if ((texture[0].ptr = mlx_xpm_file_to_image(m->mlx->ptr,
	m->info->north_t, &w, &h)) == NULL)
		ft_error_free("bad texture north", m->info);
	if ((texture[1].ptr = mlx_xpm_file_to_image(m->mlx->ptr,
	m->info->south_t, &w, &h)) == NULL)
		ft_error_free("bad texture south", m->info);
	if ((texture[2].ptr = mlx_xpm_file_to_image(m->mlx->ptr,
	m->info->west_t, &w, &h)) == NULL)
		ft_error_free("bad texture west", m->info);
	if ((texture[3].ptr = mlx_xpm_file_to_image(m->mlx->ptr,
	m->info->east_t, &w, &h)) == NULL)
		ft_error_free("bad texture east", m->info);
	if ((texture[4].ptr = mlx_xpm_file_to_image(m->mlx->ptr,
	m->info->sprite_t, &w, &h)) == NULL)
		ft_error_free("bad sprite texture", m->info);
	texture[5].ptr = NULL;
	ft_init_texture_data(texture, m);
	m->texture = texture;
	return (1);
}

void	ft_init_value(t_master *m, t_text_info *text_i, t_ray *ray)
{
	text_i->width = 64;
	text_i->height = 64;
	text_i->lineheight = (int)(m->info->ry / ray->perpwalldist);
	text_i->drawstart = -text_i->lineheight / 2 + m->info->ry / 2;
	if (text_i->drawstart < 0)
		text_i->drawstart = 0;
	text_i->drawend = text_i->lineheight / 2 + m->info->ry / 2;
	if (text_i->drawend >= m->info->ry)
		text_i->drawend = m->info->ry - 1;
	if (ray->side == 0)
		text_i->wallx = m->player->pos_y + ray->perpwalldist
	* ray->raydir_y;
	else
		text_i->wallx = m->player->pos_x + ray->perpwalldist
	* ray->raydir_x;
	text_i->wallx -= floor(text_i->wallx);
	text_i->x = (int)(text_i->wallx * (double)text_i->width);
	if (ray->side == 0 && ray->raydir_x > 0)
		text_i->x = text_i->width - text_i->x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		text_i->x = text_i->width - text_i->x - 1;
}

void	ft_texture(t_master *m, t_ray *ray, int x)
{
	t_text_info		text_i;

	ft_init_value(m, &text_i, ray);
	if (ray->side == 1)
		ft_draw_texture_sn(m, m->texture, &text_i, x);
	else
		ft_draw_texture_ew(m, m->texture, &text_i, x);
}
