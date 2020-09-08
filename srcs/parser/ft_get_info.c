/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:41:25 by jcueille          #+#    #+#             */
/*   Updated: 2020/09/08 18:01:29 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int			ft_texture_path_north_south(char *s, t_info *info_map)
{
	int		i;

	i = 2;
	ft_space_skip(s, &i);
	if (s[0] == 'N')
	{
		if (info_map->north_t[0] != '\0')
			ft_error("north texture specified two times");
		ft_strcpy(info_map->north_t, &s[i]);
		ft_trim(info_map->north_t);
	}
	else if (s[0] == 'S' && s[1] == 'O')
	{
		if (info_map->south_t[0] != '\0')
			ft_error("south texture specified two times");
		ft_strcpy(info_map->south_t, &s[i]);
		ft_trim(info_map->south_t);
	}
	return (1);
}

void		ft_color_trim(int k, char *s)
{
	int		j;

	j = 0;
	while (s[k])
	{
		if (s[k] == ' ')
			s[k] = '\0';
		if (s[k] == ',')
			j++;
		k++;
	}
	if (j > 2)
		ft_error("Too many commas in color.");
}

int			ft_convert_rgb_to_integer(char *s)
{
	int		i;
	int		nb[4];
	char	**tab;

	i = 1;
	ft_space_skip(s, &i);
	ft_color_trim(i, s);
	tab = ft_split(&s[i], ',');
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
