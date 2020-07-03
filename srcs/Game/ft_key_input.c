/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:40:47 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/08 16:40:50 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>

int					ft_key_release(int keycode, t_move *move)
{
	if (keycode == ESC)
		move->esc = 0;
	else if (keycode == UP)
		move->foward = 0;
	else if (keycode == DOWN)
		move->retreat = 0;
	else if (keycode == LEFT)
		move->left = 0;
	else if (keycode == RIGHT)
		move->right = 0;
	else if (keycode == KEY_LEFT)
		move->turn_left = 0;
	else if (keycode == KEY_RIGHT)
		move->turn_right = 0;
	else if (keycode == KEY_SHIFT)
		move->sprint = 0;
	return (0);
}

int					ft_key_press(int keycode, t_move *move)
{
	if (keycode == ESC)
		move->esc = 1;
	else if (keycode == UP)
		move->foward = 1;
	else if (keycode == DOWN)
		move->retreat = 1;
	else if (keycode == LEFT)
		move->left = 1;
	else if (keycode == RIGHT)
		move->right = 1;
	else if (keycode == KEY_LEFT)
		move->turn_left = 1;
	else if (keycode == KEY_RIGHT)
		move->turn_right = 1;
	else if (keycode == KEY_SHIFT)
		move->sprint = 1;
	else if (keycode == KEY_ONE)
		move->texture = 1;
	else if (keycode == KEY_TWO)
		move->texture = 0;
	return (0);
}
