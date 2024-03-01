/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:03:07 by djin              #+#    #+#             */
/*   Updated: 2024/03/01 16:32:49 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_s_so_long(t_so_long *so_long, char **argv)
{
	(void)argv;
	so_long->mlx = mlx_init();
	so_long->player = ft_calloc(1, sizeof(t_player));
	so_long->win = mlx_new_window(so_long->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
	TITLE);
	so_long->lst_map = NULL;
}
