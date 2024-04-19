/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:38:36 by geibo             #+#    #+#             */
/*   Updated: 2024/04/20 01:47:42 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_long *so_long)
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

int	close_win(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (so_long->enemy->img[i])
	{
		mlx_destroy_image(so_long->mlx, so_long->enemy->img[i]);
		i++;
	}
	mlx_destroy_image(so_long->mlx, so_long->sprite_img.floor);
	mlx_destroy_image(so_long->mlx, so_long->sprite_img.wall);
	mlx_destroy_image(so_long->mlx, so_long->player->up);
	mlx_destroy_image(so_long->mlx, so_long->player->down);
	mlx_destroy_image(so_long->mlx, so_long->player->left);
	mlx_destroy_image(so_long->mlx, so_long->player->right);
	free_map(so_long);
	free(so_long->player);
	free(so_long->enemy->img);
	free(so_long->enemy);
	mlx_destroy_window(so_long->mlx, so_long->win);
	free(so_long->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	move_enemy(t_so_long *so_long)
{
	if (so_long->enemy->direction == 1)
	{
		if (so_long->map[so_long->enemy->ep[1]] \
		[so_long->enemy->ep[0] + 1] == '0')
			so_long->enemy->ep[0]++;
		else
		{
			so_long->enemy->ep[0]--;
			so_long->enemy->direction = 0;
		}
	}
	else
	{
		if (so_long->enemy->ep[0] > 0
			&& so_long->map[so_long->enemy->ep[1]] \
			[so_long->enemy->ep[0] - 1] == '0')
			so_long->enemy->ep[0]--;
		else
		{
			so_long->enemy->ep[0]++;
			so_long->enemy->direction = 1;
		}
	}
	so_long->enemy->img_index = 0;
}

void	animation_condition(t_so_long *so_long)
{
	if (so_long->enemy->frame == 250)
		so_long->enemy->frame = 0;
	if (so_long->enemy->ep[0] == so_long->player->pp[0]
		&& so_long->enemy->ep[1] == so_long->player->pp[1])
		game_over(so_long);
	if (so_long->enemy->img_index == 0
		&& so_long->enemy->direction == 1
		&& so_long->map[so_long->enemy->ep[1]] \
			[so_long->enemy->ep[0] - 1] == '0')
		put_img(so_long, so_long->enemy->ep[0] - 1, \
		so_long->enemy->ep[1], so_long->sprite_img.floor);
	if (so_long->enemy->img_index == 0 && so_long->enemy->direction == 0
		&& so_long->map[so_long->enemy->ep[1]] \
			[so_long->enemy->ep[0] + 1] == '0')
		put_img(so_long, so_long->enemy->ep[0] + 1, \
		so_long->enemy->ep[1], so_long->sprite_img.floor);
	put_img(so_long, so_long->enemy->ep[0], \
	so_long->enemy->ep[1], so_long->sprite_img.floor);
	put_img(so_long, so_long->enemy->ep[0], \
	so_long->enemy->ep[1], \
	so_long->enemy->img[so_long->enemy->img_index]);
	so_long->enemy->img_index++;
	if (so_long->enemy->img_index == 5)
		move_enemy(so_long);
}

int	animation(t_so_long *so_long)
{
	so_long->enemy->frame++;
	if (so_long->enemy->frame == 250)
		animation_condition(so_long);
	return (0);
}
