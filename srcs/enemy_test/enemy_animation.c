/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:41:21 by djin              #+#    #+#             */
/*   Updated: 2024/04/15 17:01:06 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	monster_move_direction(t_monster *m, t_so_long *so_long)
{
	int	dist;

	if (m->mi > 4)
	{
		m->mi = 0;
		if (m->direction == 1)
		{
			dist = get_mrwc(m, so_long);
			m->pp[0] = m->pp[0] + dist;
			if (m->pp[0] > m->init_p[0] + (BPX * 2) || dist == 0)
				m->direction = 0;
		}
		else
		{
			dist = get_mlwc(m, so_long);
			m->pp[0] = m->pp[0] - dist;
			if (m->pp[0] < m->init_p[0] - (BPX * 2) || dist == 0)
				m->direction = 1;
		}
	}
	m->mi++;
}

void	monster_position(t_monster *monster)
{
	monster->a[0] = monster->pp[0];
	monster->a[1] = monster->pp[1];
	monster->b[0] = monster->pp[0];
	monster->b[1] = monster->pp[1] + BPX;
	monster->c[0] = monster->pp[0] + BPX;
	monster->c[1] = monster->pp[1];
	monster->d[0] = monster->pp[0] + BPX;
	monster->d[1] = monster->pp[1] + BPX;
}

void	monster_move(t_so_long *so_long)
{
	t_node		*current_node;
	t_monster	*monster;

	current_node = so_long->enemy_lst;
	while (current_node)
	{
		monster = (t_monster *)current_node->content;
		monster_position(monster);
		if (monster->move == 1)
			monster_move_direction(monster, so_long);
		current_node = current_node->next;
	}
}

void	monster(t_so_long *so_long)
{
	monster_move(so_long);
	
}
