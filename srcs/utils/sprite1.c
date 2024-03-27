/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:12:14 by geibo             #+#    #+#             */
/*   Updated: 2024/03/27 13:35:26 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite_type(t_so_long *so_long, char *path, int s_type)
{
	if (ft_strcmp(OS, "Linux") == 0)
		load_sprite_xpm(so_long, path, s_type);
	// else
	// 	load_sprite_png(so_long, path, s_type);
}

char	*path_sprite(int type)
{
	if (type == WALL)
		return ("./sprites/Block.xpm");
	return (NULL);
}

void	load_sprite(t_so_long *so_long, int s_type)
{
	int		fd;
	char	*path;

	path = path_sprite(s_type);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error("Invalid sprite path");
	close(fd);
	load_sprite_type(so_long, path, s_type);
}

void	init_sprites(t_so_long *so_long)
{
	load_sprite(so_long, WALL);
}
