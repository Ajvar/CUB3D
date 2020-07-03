/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:22:04 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/24 15:27:50 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		ft_info_order(t_info *d)
{
	if ((d->rx == 0 && d->ry == 0) || d->north_t[0] == '\0' ||
	d->south_t[0] == '\0' || d->west_t[0] == '\0' || d->east_t[0] == '\0'
	|| d->sprite_t[0] == '\0' || d->colorc == -1 || d->colorf == -1)
		ft_error("missing argument, map must be at the end of file");
}

static void		ft_map(t_info *info_map, char *line)
{
	int			n;

	n = 0;
	if (!(info_map->map_struct))
	{
		info_map->map_struct = ft_lstnew(line);
		info_map->len_y++;
	}
	else
	{
		ft_lstadd_back(&info_map->map_struct, ft_lstnew(line));
		info_map->len_y++;
		if ((n = (int)ft_strlen(line)) > info_map->l_map)
			info_map->l_map = n;
	}
}

/*
	***	Check ID et appelle la bonne fonction
*/

void			ft_check_id(char *line, t_info *info_map)
{
	int			i;

	i = 0;
	ft_space_skip(line, &i);
	if ((line[i] == 'N' && line[i + 1] == 'O') ||
	(line[i] == 'S' && line[i + 1] == 'O'))
		ft_texture_path_north_south(&line[i], info_map);
	else if ((line[i] == 'W' && line[i + 1] == 'E')
	|| (line[i] == 'E' && line[i + 1] == 'A') ||
	(line[i] == 'S' && line[i + 1] == ' '))
		ft_texture_path_west_east(&line[i], info_map);
	else if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
		ft_colors(&line[i], info_map);
	else if (line[i] == 'R')
		ft_resolution(&line[i], info_map);
	else if (line[i] == '1')
	{
		ft_info_order(info_map);
		ft_map(info_map, line);
	}
	else if (line[i] != '\n' && line[i] != '\0')
		ft_error("wrong character");
}

void			ft_parse(t_info *info_map, int *fd)
{
	char		*line;

	while (get_next_line(*fd, &line) != 0)
	{
		ft_check_id(line, info_map);
		free(line);
	}
	ft_check_id(line, info_map);
	close(*fd);
	info_map->map = ft_map_filler(info_map);
	ft_is_map_valid(info_map);
	if (info_map->len_y < 3)
		ft_error("map too small.");
	free(line);
}
