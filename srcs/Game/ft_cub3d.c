/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:42:02 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/29 17:56:11 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				ft_print_img(t_master *m)
{
	int			i;

	i = 0;
	m->mlx->img = mlx_new_image(m->mlx->ptr, m->info->rx, m->info->ry);
	m->mlx->data_img = mlx_get_data_addr(m->mlx->img, &m->mlx->bpixel,
	&m->mlx->size_line, &m->mlx->endian);
	m->mlx->bpixel = m->mlx->bpixel / 8;
	while (i < m->info->rx * (m->info->ry / 2))
		*(int *)&m->mlx->data_img[i++ * m->mlx->bpixel] = m->info->colorc;
	while (i < m->info->rx * (m->info->ry))
		*(int *)&m->mlx->data_img[i++ * m->mlx->bpixel] = m->info->colorf;
	ft_raycaster(m, m->ray);
	ft_sprite(m, m->sprite, m->info->sprite_nb);
	free(m->zbuffer);
	ft_player_pos_cam(m, m->player);
	if (m->save == 0)
		mlx_put_image_to_window(m->mlx->ptr, m->mlx->win, m->mlx->img, 0, 0);
	if (m->save == 0)
		mlx_destroy_image(m->mlx->ptr, m->mlx->img);
	if (m->move->esc == 1)
		ft_exit_prog(m);
	return (0);
}

static int		ft_game(t_info *map, t_mlx *mlx, int save)
{
	t_ray		ray;
	t_master	master;
	t_texture	texture[6];
	t_move		move;
	t_player	player;

	if ((mlx->ptr = mlx_init()) == NULL)
		ft_error("mlx init failed");
	ft_pos_sprite(map, &master);
	ft_init_struct_move(&move);
	ft_init_struct_player(&player);
	ft_init_ray(&ray);
	ft_fill_master(&move, &ray, &master, save);
	ft_init_master(map, mlx, &player, &master);
	ft_init_pos_player(&master, &player);
	if (!(mlx->win = mlx_new_window(mlx->ptr, map->rx, map->ry, "Cub3d")))
		ft_error("window init failed");
	if ((ft_init_texture(&master, texture, 64, 64) == 0))
		return (0);
	mlx_hook(mlx->win, KEYPRESS, KEYPRESS_MASK, ft_key_press, &move);
	mlx_hook(mlx->win, KEYRELEASE, KEYRELEASE_MASK, ft_key_release, &move);
	mlx_hook(mlx->win, 17, 1L << 17, ft_exit_prog, &master);
	mlx_loop_hook(mlx->ptr, ft_print_img, &master);
	mlx_loop(mlx->ptr);
	return (0);
}

static int		ft_init_program(int save, char **av, t_mlx mlx)
{
	t_info		info_map;
	int			fd;

	ft_init_struct_infomap(&info_map);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error("can't open file");
	ft_parse(&info_map, &fd);
	ft_sprite_count(&info_map);
	if (info_map.sprite_nb > 49)
		ft_error("max sprite 49");
	if (save == 1)
		ft_save(&info_map, &mlx);
	else
		ft_game(&info_map, &mlx, save);
	return (0);
}

static void		ft_check_args(char **argv, int argc, int *save)
{
	if (argc > 3 || argc < 2)
		ft_error("wrong number of arguments");
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7) != 0)
			ft_error("wrong option.");
		else
			*save = 1;
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		ft_error("wrong file format, must be a .cub as argument");
}

int				main(int ac, char **av)
{
	int			save;
	t_mlx		mlx;

	save = 0;
	mlx.ptr = 0;
	ft_check_args(av, ac, &save);
	ft_init_program(save, av, mlx);
	return (0);
}
