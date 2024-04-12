/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:57:44 by geibo             #+#    #+#             */
/*   Updated: 2024/04/12 16:53:51 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	so_long;

	init_s_so_long(&so_long);
	init_map(argc, argv, &so_long);
	mlx_hook(so_long.win, DESTROY, 1L << 17, close_win, &so_long);
	mlx_loop(so_long.mlx);
}
