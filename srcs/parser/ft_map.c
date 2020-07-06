/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:12:58 by jcueille          #+#    #+#             */
/*   Updated: 2020/07/06 14:44:51 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char		**ft_map_filler(t_info *info_map)
{
	char	**tmp;
	int		i;
	int		k;
	t_map	*map_ptr;

	if (!(tmp = ft_calloc(info_map->len_y + 1, sizeof(char *))))
		ft_error("malloc error");
	map_ptr = info_map->map_struct;
	i = 0;
	while (i < info_map->len_y)
	{
		tmp[i] = malloc(info_map->l_map + 1);
		k = ft_strlcpy(tmp[i], map_ptr->line, info_map->l_map + 1);
		if (tmp[i][ft_strlen(tmp[i]) - 1] != '1')
			ft_error_map_fill(tmp, "wrong map (one line isn't closed)", i);
		while (k < info_map->l_map)
		{
			tmp[i][k] = ' ';
			k++;
		}
		tmp[i][k] = '\0';
		map_ptr = map_ptr->next;
		i++;
	}
	return (tmp);
}

static void	ft_check_first_last(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] != '1' && s[i] != ' ')
			ft_error("wrong map (first or last line)");
}

static void	ft_is_map_valid_bis(t_info *info_map, int *i, int *k)
{
	if ((*k != 0 && info_map->map[*i][*k - 1] != '1'
	&& info_map->map[*i][*k - 1] != ' ')
	|| (*k + 1 != (int)ft_strlen(info_map->map[*i])
	&& info_map->map[*i][*k + 1] != '1' && info_map->map[*i][*k + 1] != ' ')
	|| (*i != 0 && info_map->map[*i - 1][*k] != '1'
	&& info_map->map[*i - 1][*k] != ' ')
	|| (*i + 1 != info_map->len_y && info_map->map[*i + 1][*k] != '1'
	&& info_map->map[*i + 1][*k] != ' '))
		ft_error_free("wrong map", info_map);
}

static void	ft_direction_found(t_info *info_map, int i, int k)
{
	if (info_map->player_start != '0')
		ft_error("player position specified two times");
	info_map->player_start = info_map->map[i][k];
	info_map->player_x = k + 0.5;
	info_map->player_y = i + 0.5;
	info_map->map[i][k] = '0';
}

void		ft_is_map_valid(t_info *info_map)
{
	int		i;
	int		k;

	i = 0;
	while (i < info_map->len_y)
	{
		k = 0;
		while (info_map->map[i][k])
		{
			if (info_map->map[i][k] == ' ')
				ft_is_map_valid_bis(info_map, &i, &k);
			else if (ft_pos_check(info_map->map[i][k]))
				ft_direction_found(info_map, i, k);
			else if (info_map->map[i][k] != '1' && info_map->map[i][k] != '2'
			&& info_map->map[i][k] != '0')
				ft_error("wrong character in the map.");
			k++;
		}
		i++;
	}
	ft_check_first_last(info_map->map[0]);
	ft_check_first_last(info_map->map[i - 1]);
	if (info_map->player_start == '0')
		ft_error_free("No player position specified", info_map);
}
