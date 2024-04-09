/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:12:44 by geibo             #+#    #+#             */
/*   Updated: 2024/04/09 16:08:55 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < so_long->gh)
	{
		j = 0;
		while (j < so_long->gw)
		{
			if (so_long->map[i][j] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->win, \
				so_long->map_img.wall, (so_long->map_cord->x + j * 100), \
				(so_long->map_cord->y + i * 100));
			j++;
		}
		i++;
	}
}

void	wall(t_so_long *so_long)
{
	draw_wall(so_long);
}
