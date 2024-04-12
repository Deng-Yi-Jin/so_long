/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:01:26 by geibo             #+#    #+#             */
/*   Updated: 2024/04/12 16:53:00 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_s_so_long(t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	so_long->map_fd = -1;
	so_long->gw = -1;
	so_long->gh = -1;
	so_long->player = ft_calloc(1, sizeof(t_player));
	if (!so_long->player)
		error("Fail to allocate memory");
	so_long->win = mlx_new_window(so_long->mlx, WINDOW_WIDTH, \
					WINDOW_HEIGHT, TITLE);
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
	// printf("hi");
	// if (convert_node(so_long))
	// 	error("Fail to convert node");
}
