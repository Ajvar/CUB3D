/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:24 by jcueille          #+#    #+#             */
/*   Updated: 2020/07/06 14:52:37 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../mlx/mlx_int.h"

static void			mlx_terminate(t_master *m)
{
	struct s_xvar	*xvar;
	int				y;

	y = 0;
	while (y < 5)
	{
		mlx_destroy_image(m->mlx->ptr, m->texture[y].ptr);
		m->texture[y].ptr = NULL;
		m->texture[y].img = NULL;
		y++;
	}
	m->mlx->img = NULL;
	if (m->mlx->win)
	{
		mlx_clear_window(m->mlx->ptr, m->mlx->win);
		mlx_destroy_window(m->mlx->ptr, m->mlx->win);
	}
	xvar = m->mlx->ptr;
	if (xvar->private_cmap)
		XFreeColormap(xvar->display, (Colormap)xvar->private_cmap);
	XCloseDisplay(xvar->display);
	free(xvar);
}

int					ft_exit_prog(t_master *m)
{
	t_map			*tmp;
	int				y;

	y = 0;
	while (m->info->map[y])
	{
		free(m->info->map[y]);
		y++;
	}
	free(m->info->map[y]);
	free(m->info->map);
	mlx_terminate(m);
	tmp = m->info->map_struct;
	while (m->info->map_struct != NULL)
	{
		tmp = m->info->map_struct;
		m->info->map_struct = m->info->map_struct->next;
		free(tmp->line);
		free(tmp);
	}
	exit(0);
	return (1);
}
