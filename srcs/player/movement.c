/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:02:07 by geibo             #+#    #+#             */
/*   Updated: 2024/04/09 00:15:43 by geibo            ###   ########.fr       */
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
		so_long->player->pp[1] -= BPX;
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->map_img.player, so_long->map_cord->x + so_long->player->pp[0], \
		so_long->map_cord->y + so_long->player->pp[1]);
		so_long->player->step++;
	}
}
