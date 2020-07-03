/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:33:55 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/26 15:06:40 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int		ft_atoi(char *str)
{
	int		i;
	int		nb;
	int		negpos;

	i = 0;
	nb = 0;
	negpos = 1;
	while ((str[i] == ' ') || (str[i] > 6 && str[i] < 14))
		i++;
	if (str[i] == '-')
		negpos = negpos * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = nb * negpos;
	return (nb);
}

int		ft_isdigit(char *s)
{
	int		i;

	i = 0;
	ft_space_skip(s, &i);
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}
