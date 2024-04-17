/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:01:23 by djin              #+#    #+#             */
/*   Updated: 2024/04/17 16:29:15 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_monster_sprite(t_monster *m, t_so_long *so_long)
{
	if (m->ai == 4)
	{
		m->ai = 0;
	}
}

void	draw_block(int x, int y, void *sprite, t_so_long *so_long)
{
	if (x < -BPX || y < -BPX || x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
		return ;
	mlx_put_image_to_window(so_long->mlx, so_long->win,
		sprite, x + so_long->go[0], y + so_long->go[1]);
}

void	draw_monster(t_so_long *so_long)
{
	t_node		*current_node;
	t_monster	*m;

	current_node = so_long->enemy_lst;
	while (current_node)
	{
		m = (t_monster *)current_node->content;
		if (m->alive == 1 || m->td > 0)
			draw_block(m->pp[0] + so_long->po[0],
				m->pp[1] + so_long->po[1],
				get_monster_sprite(m, so_long), so_long);
	}
}
