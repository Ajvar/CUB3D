/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:41:25 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/29 14:46:57 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_resolution(char *s, t_info *info_map)
{
	int		i;

	i = 2;
	ft_space_skip(s, &i);
	if (info_map->rx > 0 || info_map->rx > 0)
		ft_error("Resolution specified two times.");
	info_map->rx = ft_atoi(&s[i]);
	while (s[i] && s[i] != ' ')
		i++;
	ft_space_skip(s, &i);
	if ((s[i] > '9' && s[i] < '0') || s[i] == '\0')
		ft_error("resolution needs two numbers");
	info_map->ry = ft_atoi(&s[i]);
	if (info_map->rx < 1 || info_map->ry < 1)
		ft_error("resolution can't be under 1");
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	ft_space_skip(s, &i);
	if (s[i] != '\0')
		ft_error("wrong char at the end of resolution");
	return (1);
}

void		ft_res_correction(t_info *map, t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_get_screen_size(mlx->ptr, &x, &y);
	if (map->rx > x)
		map->rx = x;
	if (map->ry > y)
		map->ry = y;
}

int			ft_texture_path_north_south(char *s, t_info *info_map)
{
	int		i;

	i = 2;
	while (s[i] == ' ')
		i++;
	if (s[0] == 'N')
	{
		if (info_map->north_t[0] != '\0')
			ft_error("north texture specified two times");
		ft_strcpy(info_map->north_t, &s[i]);
	}
	else if (s[0] == 'S' && s[1] == 'O')
	{
		if (info_map->south_t[0] != '\0')
			ft_error("south texture specified two times");
		ft_strcpy(info_map->south_t, &s[i]);
	}
	return (1);
}

int			ft_convert_rgb_to_integer(char *s)
{
	int		i;
	int		nb[4];
	char	**tab;

	i = 1;
	ft_space_skip(s, &i);
	tab = ft_split(&s[i], ',');
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		ft_error("incorrect color format");
	i = -1;
	while (++i < 3)
	{
		if ((tab[i] == NULL) || ft_isdigit(tab[i]) == -1)
			ft_error("incorrect color format");
		else
			nb[i] = ft_atoi(tab[i]);
	}
	ft_free_tab(tab);
	nb[i] = ft_check_rgb(nb, i);
	return (nb[i]);
}

int			ft_colors(char *s, t_info *info_map)
{
	if (s[0] == 'F' && info_map->colorf == -1)
		info_map->colorf = ft_convert_rgb_to_integer(s);
	else if (s[0] == 'C' && info_map->colorc == -1)
		info_map->colorc = ft_convert_rgb_to_integer(s);
	else
		ft_error("color spcified two times");
	if (info_map->colorf == -1 || info_map->colorc == -1)
		return (0);
	return (1);
}
