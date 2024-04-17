/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:47:51 by geibo             #+#    #+#             */
/*   Updated: 2024/04/16 21:33:53 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	monster_death_sprite(t_monster *m)
{
	if (m->la != 3)
		m->img_index = 0;
	m->la = 3;
	if (m->direction == 1)
	{
		if (m->img_index > 6 && m->img_index < 10)
			m->img_index++;
		else
			m->img_index = 7;
	}
	else
	{
		if (m->img_index > 17 && m->img_index < 21)
			m->img_index++;
		else
			m->img_index = 18;
	}
	return (m->img_index);
}

static int	monster_attack_sprite(t_monster *m)
{
	if (m->la != 2)
		m->img_index = 0;
	m->la = 2;
	if (m->direction == 1)
	{
		if (m->img_index > 2 && m->img_index < 6)
			m->img_index++;
		else
			m->img_index = 3;
	}
	else
	{
		if (m->img_index > 13 && m->img_index < 17)
			m->img_index++;
		else
			m->img_index = 14;
	}
	return (m->img_index);
}

static int	monster_move_sprite(t_monster *m)
{
	if (m->la != 1)
		m->img_index = 0;
	m->la = 1;
	if (m->direction == 1)
	{
		if (m->img_index > -1 && m->img_index < 3)
			m->img_index++;
		else
			m->img_index = 0;
	}
	else
	{
		if (m->img_index > 10 && m->img_index < 14)
			m->img_index++;
		else
			m->img_index = 11;
	}
	return (m->img_index);
}

static void	monster_sprite_pos(t_monster *m)
{
	// if (m->td > 0)
	// 	monster_death_sprite(m);
	// else if (m->ta > 0)
	// 	monster_attack_sprite(m);
	// else
		monster_move_sprite(m);
}

int	*get_monster_sprite(t_monster *m, t_so_long *so_long)
{
	if (m->ai == 4)
	{
		m->ai = 0;
		monster_sprite_pos(m);
	}
	else
		m->ai++;
	return (so_long->ms[m->img_index]);
}
