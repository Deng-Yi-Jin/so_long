/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:49:48 by geibo             #+#    #+#             */
/*   Updated: 2024/03/27 15:10:55 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	key_hook(int keycode, t_so_long *so_long)
{
	(void)keycode;
	mlx_destroy_window(so_long->mlx, so_long->win);
	exit(EXIT_SUCCESS);
	return (0);
}
