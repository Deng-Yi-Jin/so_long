/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:18:56 by djin              #+#    #+#             */
/*   Updated: 2024/04/15 15:24:46 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_monster(int x, int y, t_so_long *so_long)
{
	t_monster	*monster;

	monster = ft_calloc(1, sizeof(t_enemy));
	if (monster == NULL)
		error_free("Fail to allocate memory", so_long);
	monster->pp[0] = x * BPX;
	monster->pp[1] = y * BPX;
	monster->init_p[0] = monster->pp[0];
	monster->init_p[1] = monster->pp[1];
	monster->alive = 1;
	monster->direction = 1;
	monster->move = 1;
	monster->ai = 0;
	monster->td = 0;
	if (so_long->enemy_lst == NULL)
		so_long->enemy_lst = ft_lstnew(monster);
	else
		ft_lstadd_back(&so_long->enemy_lst, ft_lstnew(monster));
}

void	analyse_monster(t_so_long *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (y < so_long->gh)
	{
		x = 0;
		while (x < so_long->gw)
		{
			if (so_long->map[y][x] == 'M')
				create_monster(x, y, so_long);
			x++;
		}
		y++;
	}
}
