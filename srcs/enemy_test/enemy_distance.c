/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:01:29 by djin              #+#    #+#             */
/*   Updated: 2024/04/15 16:51:55 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_collision(char c, int type)
{
	if (type == 1)
	{
		if (c == '1')
			return (1);
	}
	else
	{
		if (c == '0')
			return (1);
		else if (c == '*')
			return (1);
		else if (c == 'C')
			return (1);
		else if (c == 'E')
			return (1);
		else if (c == 'M')
			return (1);
	}
	return (0);
}

int	get_mrwc(t_monster *monster, t_so_long *so_long)
{
	int			dist_coll;
	t_monster	*m;

	m = monster;
	if (is_collision(so_long->map[m->c[1] / BPX][m->c[0] / BPX+1], 1))
	{
		if (is_collision(so_long->map[m->c[1] / BPX][m->c[0] / BPX], 1))
			return (1);
		dist_coll = BPX + (BPX * (m->c[0] / BPX - m->c[0])) - 1;
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	else if (is_collision(so_long->map[m->c[1] / BPX][m->c[0] / BPX+1], 0))
	{
		if (is_collision(so_long->map[m->c[1] / BPX][m->c[0] / BPX], 0))
			return (1);
		dist_coll = BPX + (BPX * (m->c[0] / BPX - m->c[0])) - 1;
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	return (MPX);
}

int	get_mlwc(t_monster *monster, t_so_long *so_long)
{
	int			dist_coll;
	t_monster	*m;

	m = monster;
	if (is_collision(so_long->map[m->a[1] / BPX][m->a[0] / BPX-1], 1))
	{
		if (is_collision(so_long->map[m->a[1] / BPX][m->a[0] / BPX], 1))
			return (1);
		dist_coll = BPX - (BPX * (m->a[0] / BPX - m->a[0])) - 1;
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	else if (is_collision(so_long->map[m->a[1] / BPX][m->a[0] / BPX-1], 0))
	{
		if (is_collision(so_long->map[m->a[1] / BPX][m->a[0] / BPX], 0))
			return (1);
		dist_coll = BPX - (BPX * (m->a[0] / BPX - m->a[0])) - 1;
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	return (MPX);
}
