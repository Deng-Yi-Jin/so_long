/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:19:28 by djin              #+#    #+#             */
/*   Updated: 2024/04/08 15:01:54 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite_xpm(t_so_long *so_long, char *path, int s_type)
{
	int	block_pixel;

	block_pixel = BPX;
	if (s_type == WALL)
	{
		so_long->map_img.wall = mlx_xpm_file_to_image(so_long->mlx, path, \
		&block_pixel, &block_pixel);
	}
	if (s_type == PLAYER)
	{
		so_long->map_img.player = mlx_xpm_file_to_image(so_long->mlx, path, \
		&block_pixel, &block_pixel);
	
	}
	if (so_long->map_img.wall == NULL)
		error("Fail to generate image");
}
