/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:37:30 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/24 15:07:00 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_check_rgb(int nb[4], int n)
{
	if (nb[0] > 255 || nb[1] > 255 || nb[2] > 255)
		ft_error("wrong RGB value");
	else if (nb[0] < 0 || nb[1] < 0 || nb[2] < 0)
		ft_error("wrong RGB value");
	else
		nb[n] = 65536 * nb[0] + 256 * nb[1] + nb[2];
	return (nb[n]);
}

int		ft_texture_path_west_east(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	while (s[i] == ' ')
		i++;
	if (s[0] == 'W')
	{
		if (info_map->west_t[0] != '\0')
			ft_error("duplicate texture west");
		ft_strcpy(info_map->west_t, &s[i]);
	}
	else if (s[0] == 'E')
	{
		if (info_map->east_t[0] != '\0')
			ft_error("duplicate texture east");
		ft_strcpy(info_map->east_t, &s[i]);
	}
	else if (s[0] == 'S')
	{
		if (info_map->sprite_t[0] != '\0')
			ft_error("duplicate texture sprite");
		ft_strcpy(info_map->sprite_t, &s[i]);
	}
	return (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		ft_rgb_space(char **tab, int i)
{
	int	n;
	int	valid;

	n = 0;
	valid = 0;
	while (tab[i][n])
	{
		if (tab[i][n] != ' ')
			valid = 1;
		n++;
	}
	if (valid == 0)
		return (0);
	return (1);
}

void	ft_space_skip(char *s, int *i)
{
	if (s[*i] == ' ')
	{
		while (s[*i] == ' ')
			(*i)++;
	}
}
