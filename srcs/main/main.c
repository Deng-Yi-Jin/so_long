/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:27:10 by djin              #+#    #+#             */
/*   Updated: 2024/03/25 10:35:42 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #include <stdio.h>

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
	mlx_loop(so_long.mlx);
	free(so_long.player);
	exit(EXIT_SUCCESS);
}
