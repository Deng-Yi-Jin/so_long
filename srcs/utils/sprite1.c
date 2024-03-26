/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:12:14 by geibo             #+#    #+#             */
/*   Updated: 2024/03/26 17:22:30 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite_type(char *type, t_so_long *so_long, char *path)
{
	if (ft_strcmp(OS, "Linux") == 0)
		load_sprite_xpm(type, so_long, path);
	else
		load_sprite_png(type, so_long, path);
}

char	*path_sprite(char *type)
{
	if (ft_strncmp(type, "Wall", 4) == 0)
		return ("./sprites/Block.xpm");
	return (NULL);
}

void	load_sprite(char *type, t_so_long *so_long)
{
	int		fd;
	char	*path;

	path_sprite(type) == NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error("Invalid sprite path");
	close(fd);
	load_sprite_type(type, so_long, path);
}

void	init_sprites(t_so_long *so_long)
{
	load_sprite("Wall", so_long);
}
