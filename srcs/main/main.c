/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:27:10 by djin              #+#    #+#             */
/*   Updated: 2024/04/09 16:05:04 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #include <stdio.h>

static int	game_loop(t_so_long *so_long)
{
	wall(so_long);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_so_long	so_long;

	(void)envp;
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	init_s_so_long(&so_long, argv);
	init_map(argc, argv, &so_long);
	// print_map(so_long);
	init_sprites(&so_long);
	init_player(&so_long);
	printf("OK\n");
	printf("player->pp[0]: %d, player->pp[1]: %d\n", so_long.player->pp[0] / BPX, so_long.player->pp[1] / BPX);
	mlx_key_hook(so_long.win, key_hook, &so_long);
	mlx_loop_hook(so_long.mlx, game_loop, &so_long);
	mlx_loop(so_long.mlx);
	free(so_long.player);
	exit(EXIT_SUCCESS);
}
