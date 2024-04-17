/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 02:23:55 by geibo             #+#    #+#             */
/*   Updated: 2024/04/17 22:44:44 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_collect(t_so_long *so_long, int x, int y)
{
	int	i;
	int	line;

	line = 0;
	so_long->map[y][x] = '0';
	while (so_long->map[line])
	{
		i = 0;
		while (so_long->map[line][i])
		{
			if (so_long->map[line][i] == 'E')
				break ;
			i++;
		}
		if (so_long->map[line][i] == 'E')
			break ;
		line++;
	}
	if (!check_collectible(so_long))
	{
		put_img(so_long, i, line, so_long->sprite_img.exit1);
		so_long->exit_status = 1;
	}
}

void	game_win(t_so_long *so_long)
{
	int	i;

	i = 0;
	ft_putstr_fd("You Win!\n", 1);
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
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	exit(EXIT_SUCCESS);
}

void	game_over(t_so_long *so_long)
{
	int	i;

	i = 0;
	ft_putstr_fd("Game Over\n", 1);
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
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	exit(EXIT_SUCCESS);
}
