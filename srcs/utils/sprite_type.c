/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:19:28 by djin              #+#    #+#             */
/*   Updated: 2024/03/27 13:44:36 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	load_sprite_png(t_so_long *so_long, char *path, int s_type)
// {
// 	int	width;
// 	int	height;

// 	if (s_type == WALL)
// 	{
// 		so_long->map_img->wall = mlx_png_file_to_image(so_long->mlx, path, \
// 		&width, &height);
// 	}
// 	if (so_long->map_img->wall == NULL)
// 		error("Fail to generate image");
// }

void	load_sprite_xpm(t_so_long *so_long, char *path, int s_type)
{
	int	width;
	int	height;

	if (s_type == WALL)
	{
		so_long->map_img->wall = mlx_xpm_file_to_image(so_long->mlx, path, \
		&width, &height);
	}
	if (so_long->map_img->wall == NULL)
		error("Fail to generate image");
}
