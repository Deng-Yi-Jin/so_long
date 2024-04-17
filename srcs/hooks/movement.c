/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:20:38 by geibo             #+#    #+#             */
/*   Updated: 2024/04/17 19:22:08 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_string(t_so_long *so_long)
{
	char	*str;

	str = ft_itoa(so_long->player->step);
	put_img(so_long, 2, 0, so_long->sprite_img.wall);
	ft_putstr_fd("Step: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	mlx_string_put(so_long->mlx, so_long->win, 100, 25, 0x00FFFFFF, str);
	free(str);
}

void	up(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player->pp[0];
	y = so_long->player->pp[1];
	printf("x: %d, y: %d\n", x, y);
	if (so_long->map[y - 1][x] != '1' && so_long->map[y - 1][x] != 'E')
	{
		if (x == so_long->enemy->ep[0] && y - 1 == so_long->enemy->ep[1])
			game_over(so_long);
		put_img(so_long, x, y, so_long->sprite_img.floor);
		so_long->player->pp[1] -= 1;
		put_img(so_long, x, y - 1, so_long->sprite_img.floor);
		put_img(so_long, x, y - 1, so_long->player->up);
		so_long->player->step += 1;
		put_string(so_long);
		if (so_long->map[y - 1][x] == 'C')
			move_collect(so_long, x, y - 1);
	}
	else if (so_long->map[y - 1][x] == 'E' && so_long->exit_status == 1)
		game_win(so_long);
}

void	down(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player->pp[0];
	y = so_long->player->pp[1];
	if (so_long->map[y + 1][x] != '1' && so_long->map[y + 1][x] != 'E')
	{
		if (x == so_long->enemy->ep[0] && y + 1 == so_long->enemy->ep[1])
			game_over(so_long);
		put_img(so_long, x, y, so_long->sprite_img.floor);
		so_long->player->pp[1] += 1;
		put_img(so_long, x, y + 1, so_long->sprite_img.floor);
		put_img(so_long, x, y + 1, so_long->player->down);
		so_long->player->step += 1;
		put_string(so_long);
		if (so_long->map[y + 1][x] == 'C')
			move_collect(so_long, x, y + 1);
	}
	else if (so_long->map[y + 1][x] == 'E' && so_long->exit_status == 1)
		game_win(so_long);
}

void	left(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player->pp[0];
	y = so_long->player->pp[1];
	if (so_long->map[y][x - 1] != '1' && so_long->map[y][x - 1] != 'E')
	{
		if (x - 1 == so_long->enemy->ep[0] && y == so_long->enemy->ep[1])
			game_over(so_long);
		put_img(so_long, x, y, so_long->sprite_img.floor);
		so_long->player->pp[0] -= 1;
		put_img(so_long, x - 1, y, so_long->sprite_img.floor);
		put_img(so_long, x - 1, y, so_long->player->left);
		so_long->player->step += 1;
		put_string(so_long);
		if (so_long->map[y][x - 1] == 'C')
			move_collect(so_long, x - 1, y);
	}
	else if (so_long->map[y][x - 1] == 'E' && so_long->exit_status == 1)
		game_win(so_long);
}

void	right(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player->pp[0];
	y = so_long->player->pp[1];
	if (so_long->map[y][x + 1] != '1' && so_long->map[y][x + 1] != 'E')
	{
		if (x + 1 == so_long->enemy->ep[0] && y == so_long->enemy->ep[1])
			game_over(so_long);
		put_img(so_long, x, y, so_long->sprite_img.floor);
		so_long->player->pp[0] += 1;
		put_img(so_long, x + 1, y, so_long->sprite_img.floor);
		put_img(so_long, x + 1, y, so_long->player->right);
		so_long->player->step += 1;
		put_string(so_long);
		if (so_long->map[y][x + 1] == 'C')
			move_collect(so_long, x + 1, y);
	}
	else if (so_long->map[y][x + 1] == 'E' && so_long->exit_status == 1)
		game_win(so_long);
}
