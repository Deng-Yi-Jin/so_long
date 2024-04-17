/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:01:26 by geibo             #+#    #+#             */
/*   Updated: 2024/04/17 22:48:20 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_so_long *so_long)
{
	int	width;
	int	height;

	so_long->sprite_img.floor = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/floor.xpm", &width, &height);
	so_long->sprite_img.wall = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/wall.xpm", &width, &height);
	so_long->player->up = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/up.xpm", &width, &height);
	so_long->player->down = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/down.xpm", &width, &height);
	so_long->player->left = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/left.xpm", &width, &height);
	so_long->player->right = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/right.xpm", &width, &height);
	so_long->sprite_img.coin = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/coin.xpm", &width, &height);
	so_long->sprite_img.exit = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/door.xpm", &width, &height);
	so_long->sprite_img.exit1 = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/door_open.xpm", &width, &height);
}

void	init_enemy_img(t_so_long *so_long)
{
	int	width;
	int	height;

	so_long->enemy->img = ft_calloc(6, sizeof(void *));
	if (!so_long->enemy->img)
		error_free("Fail to allocate memory", so_long);
	so_long->enemy->img[0] = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/slime1.xpm", &width, &height);
	so_long->enemy->img[1] = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/slime2.xpm", &width, &height);
	so_long->enemy->img[2] = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/slime3.xpm", &width, &height);
	so_long->enemy->img[3] = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/slime4.xpm", &width, &height);
	so_long->enemy->img[4] = mlx_xpm_file_to_image(so_long->mlx, \
		"sprites/slime5.xpm", &width, &height);
}

void	init_s_so_long(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		error("Fail to initialize mlx");
	so_long->map_fd = -1;
	so_long->gw = -1;
	so_long->gh = -1;
	so_long->player = ft_calloc(1, sizeof(t_player));
	so_long->enemy = ft_calloc(1, sizeof(t_enemy));
	if (!so_long->player)
		error("Fail to allocate memory");
	so_long->map = NULL;
	so_long->lst_map = NULL;
}

void	init_map(int argc, char **argv, t_so_long *so_long)
{
	int	line_count;

	if (!map_is_valid(argv[1], argc))
		error("Invalid map");
	if (!open_map(so_long, argv[1]))
		error("Fail to open map");
	line_count = parse_map(so_long) - 1;
	if (!check_map(so_long, line_count))
		error("Invalid map");
	printf("map is valid\n");
	if (!convert_node(so_long))
		error_free("Fail to convert node", so_long);
	if (!check_char(so_long))
		error_free("Invalid char", so_long);
}
