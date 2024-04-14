/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:38:36 by geibo             #+#    #+#             */
/*   Updated: 2024/04/15 01:39:34 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == ESC)
		close_win(so_long);
	else if (keycode == W || keycode == UP)
		up(so_long);
	else if (keycode == A || keycode == LEFT)
		left(so_long);
	else if (keycode == S || keycode == DOWN)
		down(so_long);
	else if (keycode == D || keycode == RIGHT)
		right(so_long);
	return (0);
}

int		close_win(t_so_long *so_long)
{
	// free_node(so_long->lst_map);
	free_map(so_long);
	free(so_long->player);
	exit(EXIT_SUCCESS);
	return(0);
}

static void	move_enemy(t_so_long *so_long)
{
	if (so_long->enemy->sign == 1)
	{
		if (so_long->map[so_long->enemy->ep[1]][so_long->enemy->ep[0] + 1] == '0')
			so_long->enemy->ep[0]++;
		else
		{
			so_long->enemy->ep[0]--;
			so_long->enemy->sign = 0;
		}
	}
	else
	{
		if (so_long->enemy->ep[0] > 0 && so_long->map[so_long->enemy->ep[1]][so_long->enemy->ep[0] - 1] == '0')
			so_long->enemy->ep[0]--;
		else
		{
			so_long->enemy->ep[0]++;
			so_long->enemy->sign = 1;
		}
	}
}

int		animation(t_so_long *so_long)
{
	so_long->enemy->frame++;
	if (so_long->enemy->frame == 2500)
	{
		if (so_long->enemy->frame == 2500)
			so_long->enemy->frame = 0;
		if (so_long->enemy->ep[0] == so_long->player->pp[0]
			&& so_long->enemy->ep[1] == so_long->player->pp[1])
			game_over(so_long);
		if (so_long->enemy->img_index == 0 && so_long->enemy->sign == 1
			// && so_long->enemy->ep[0] > 0
			&& so_long->map[so_long->enemy->ep[1]][so_long->enemy->ep[0] - 1] == '0')
			put_img(so_long, so_long->enemy->ep[0] - 1, so_long->enemy->ep[1], so_long->sprite_img.floor);
		if (so_long->enemy->img_index == 0 && so_long->enemy->sign == 0
			// && so_long->enemy->ep[0] < so_long->gw - 1
			&& so_long->map[so_long->enemy->ep[1]][so_long->enemy->ep[0] + 1] == '0')
			put_img(so_long, so_long->enemy->ep[0] + 1, so_long->enemy->ep[1], so_long->sprite_img.floor);
		put_img(so_long, so_long->enemy->ep[0], so_long->enemy->ep[1], so_long->sprite_img.floor);
		put_img(so_long, so_long->enemy->ep[0], so_long->enemy->ep[1], \
		so_long->enemy->img[so_long->enemy->img_index]);
		so_long->enemy->img_index++;
		if (so_long->enemy->img_index == 5)
		{
			move_enemy(so_long);
			so_long->enemy->img_index = 0;
		}
	}
	return (0);
}
