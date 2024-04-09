/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:49:48 by geibo             #+#    #+#             */
/*   Updated: 2024/04/09 15:46:32 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_so_long *so_long)
{
	if (keycode == W)
		up(so_long);
	else if (keycode == S)
		down(so_long);
	else if (keycode == A)
		left(so_long);
	else if (keycode == D)
		right(so_long);
	else if (keycode == ESC)
		close_win(so_long);
	return (0);
}

int	close_win(t_so_long *so_long)
{
	free_map(so_long);
	exit(EXIT_SUCCESS);
	return (0);
}
