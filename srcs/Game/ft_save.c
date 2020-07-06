/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 16:25:32 by jcueille          #+#    #+#             */
/*   Updated: 2020/07/06 14:58:16 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		ft_init_struct_save(t_master *master, t_save *m)
{
	m->size = 54 + 4 * master->info->rx * master->info->ry;
	m->unused = 0;
	m->offset_begin = 54;
	m->header_bytes = 40;
	m->plane = 1;
	m->bpixel = 32;
	m->fd = open("img.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (m->fd == -1)
		ft_error("couldn't open .bmp file");
}

void		ft_write_texture_bmp_file(t_master *master, int fd)
{
	int		y;
	int		x;
	int		line;

	y = 0;
	while (y < master->info->ry)
	{
		x = 0;
		line = master->info->rx * (master->info->ry - y);
		while (x < master->info->rx)
		{
			write(fd, &master->mlx->data_img[line * 4], 4);
			line++;
			x++;
		}
		y++;
	}
}

void		ft_write_bmp_file(t_master *master)
{
	t_save	m;

	ft_init_struct_save(master, &m);
	write(m.fd, "BM", 2);
	write(m.fd, &m.size, sizeof(int));
	write(m.fd, &m.unused, sizeof(int));
	write(m.fd, &m.offset_begin, sizeof(int));
	write(m.fd, &m.header_bytes, sizeof(int));
	write(m.fd, &master->info->rx, sizeof(int));
	write(m.fd, &master->info->ry, sizeof(int));
	write(m.fd, &m.plane, sizeof(short int));
	write(m.fd, &m.bpixel, sizeof(short int));
	write(m.fd, &m.unused, sizeof(int));
	write(m.fd, &m.unused, sizeof(int));
	write(m.fd, &m.unused, sizeof(int));
	write(m.fd, &m.unused, sizeof(int));
	write(m.fd, &m.unused, sizeof(int));
	write(m.fd, &m.unused, sizeof(int));
	ft_write_texture_bmp_file(master, m.fd);
	close(m.fd);
}

void		ft_save(t_info *info_map, t_mlx *mlx)
{
	t_move		move;
	t_player	player;
	t_ray		ray;
	t_master	master;
	t_texture	texture[6];

	if ((mlx->ptr = mlx_init()) == NULL)
		ft_error("mlx init failed");
	ft_pos_sprite(info_map, &master);
	ft_init_struct_move(&move);
	ft_init_struct_player(&player);
	ft_init_ray(&ray);
	ft_fill_master(&move, &ray, &master, 1);
	ft_init_master(info_map, mlx, &player, &master);
	ft_init_pos_player(&master, &player);
	master.save = 1;
	ft_init_texture(&master, texture, 64, 64);
	ft_print_img(&master);
	ft_write_bmp_file(&master);
	mlx_destroy_image(master.mlx->ptr, master.mlx->img);
	ft_exit_prog(&master);
}
