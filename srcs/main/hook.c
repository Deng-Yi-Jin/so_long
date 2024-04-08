/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:49:48 by geibo             #+#    #+#             */
/*   Updated: 2024/04/08 22:39:05 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == 53)
	{
		mlx_destroy_window(so_long->mlx, so_long->win);
		free_map(so_long);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_win(t_so_long *so_long)
{
	free_map(so_long);
	exit(EXIT_SUCCESS);
	return (0);
}
