/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:57:44 by geibo             #+#    #+#             */
/*   Updated: 2024/04/13 02:57:03 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	generate(t_so_long *so_long)
{
	so_long->win = mlx_new_window(so_long->mlx, so_long->gw * BPX,
			so_long->gh * BPX, TITLE);
	if (!so_long->win)
		error_free("Fail to generate window", so_long);
	so_long->player->step = 0;
	so_long->enemy->frame = 0;
	so_long->enemy->img_index = 0;
	get_enemy_pos(so_long);
	init_image(so_long);
	init_enemy_img(so_long);
	put_img_to_map(so_long);
}

int	main(int argc, char **argv)
{
	t_so_long	so_long;

	init_s_so_long(&so_long);
	init_map(argc, argv, &so_long);
	generate(&so_long);
	mlx_hook(so_long.win, KEYPRESS, 1L << 0, key_hook, &so_long);
	mlx_hook(so_long.win, DESTROY, 1L << 17, close_win, &so_long);
	mlx_loop_hook(so_long.mlx, animation, &so_long);
	mlx_loop(so_long.mlx);
}
