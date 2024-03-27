/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:27:10 by djin              #+#    #+#             */
/*   Updated: 2024/03/27 15:07:27 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #include <stdio.h>

static int	game_loop(t_so_long *so_long)
{
	wall(so_long);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_so_long	so_long;

	(void)envp;
	(void)game_loop;
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	init_s_so_long(&so_long, argv);
	init_map(argc, argv, &so_long);
	print_map(so_long);
	init_sprites(&so_long);
	mlx_hook(so_long.win, 2, 1L << 0, key_hook, &so_long);
	mlx_loop_hook(so_long.mlx, game_loop, &so_long);
	mlx_loop(so_long.mlx);
	free(so_long.player);
	exit(EXIT_SUCCESS);
}
