/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:02:07 by geibo             #+#    #+#             */
/*   Updated: 2024/04/09 15:54:31 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player->pp[0];
	y = so_long->player->pp[1];
	if (so_long->map[y / BPX - 1][x / BPX] != '1'
		&& so_long->map[y / BPX - 1][x / BPX] != 'E')
	{
		printf("up\n");
		so_long->player->pp[1] -= BPX;
		printf("x: %d, y: %d\n", so_long->player->pp[0] / BPX, so_long->player->pp[1] / BPX);
		if (so_long->map[y / BPX][x / BPX + 1] == 'C')
			so_long->map[y / BPX][x / BPX + 1] = '0';
		// else if (so_long->map[y / BPX][x / BPX + 1] == 'E')
		// {
		// 	mlx_destroy_window(so_long->mlx, so_long->win);
		// 	free_map(so_long);
		// 	free(so_long->player);
		// 	free(so_long->map_cord);
		// 	free(so_long);
		// 	exit(EXIT_SUCCESS);
		// }
	}
}

void	down(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player->pp[0];
	y = so_long->player->pp[1];
	if (so_long->map[y / BPX + 1][x / BPX] != '1')
	{
		printf("down\n");
		so_long->player->pp[1] += BPX;
		printf("x: %d, y: %d\n", so_long->player->pp[0] / BPX, so_long->player->pp[1] / BPX);
		if (so_long->map[y / BPX][x / BPX + 1] == 'C')
			so_long->map[y / BPX][x / BPX + 1] = '0';
		// else if (so_long->map[y / BPX][x / BPX + 1] == 'E')
		// {
		// 	mlx_destroy_window(so_long->mlx, so_long->win);
		// 	free_map(so_long);
		// 	free(so_long->player);
		// 	free(so_long->map_cord);
		// 	free(so_long);
		// 	exit(EXIT_SUCCESS);
		// }
	}
}

void	left(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player->pp[0];
	y = so_long->player->pp[1];
	if (so_long->map[y / BPX][x / BPX - 1] != '1')
	{
		printf("left\n");
		so_long->player->pp[0] -= BPX;
		printf("x: %d, y: %d\n", so_long->player->pp[0] / BPX, so_long->player->pp[1] / BPX);
		if (so_long->map[y / BPX][x / BPX + 1] == 'C')
			so_long->map[y / BPX][x / BPX + 1] = '0';
		// else if (so_long->map[y / BPX][x / BPX + 1] == 'E')
		// {
		// 	mlx_destroy_window(so_long->mlx, so_long->win);
		// 	free_map(so_long);
		// 	free(so_long->player);
		// 	free(so_long->map_cord);
		// 	free(so_long);
		// 	exit(EXIT_SUCCESS);
		// }
	}
}

void	right(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player->pp[0];
	y = so_long->player->pp[1];
	if (so_long->map[y / BPX][x / BPX + 1] != '1')
	{
		printf("right\n");
		so_long->player->pp[0] += BPX;
		printf("x: %d, y: %d\n", so_long->player->pp[0] / BPX, so_long->player->pp[1] / BPX);
		if (so_long->map[y / BPX][x / BPX + 1] == 'C')
			so_long->map[y / BPX][x / BPX + 1] = '0';
		// else if (so_long->map[y / BPX][x / BPX + 1] == 'E')
		// {
		// 	mlx_destroy_window(so_long->mlx, so_long->win);
		// 	free_map(so_long);
		// 	free(so_long->player);
		// 	free(so_long->map_cord);
		// 	free(so_long);
		// 	exit(EXIT_SUCCESS);
		// }
	}
}
