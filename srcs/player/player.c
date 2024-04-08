/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:02:04 by geibo             #+#    #+#             */
/*   Updated: 2024/04/08 16:46:36 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_so_long *so_long)
{
	mlx_put_image_to_window(so_long->mlx, so_long->win, \
	so_long->map_img.player, so_long->map_cord->x + so_long->player->pp[0], \
	so_long->map_cord->y + so_long->player->pp[1]);
}

void	player(t_so_long *so_long)
{
	draw_player(so_long);
}
