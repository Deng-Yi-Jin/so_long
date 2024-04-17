/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 01:33:53 by geibo             #+#    #+#             */
/*   Updated: 2024/04/17 22:23:33 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_enemy_pos(t_so_long *so_long)
{
	int	i;
	int	line;

	line = so_long->gh / 2;
	while (so_long->map[line])
	{
		i = so_long->gw / 2;
		while (so_long->map[line][i])
		{
			if (so_long->map[line][i] == '0'
			&& so_long->map[line][i + 1] == '0')
			{
				so_long->enemy->ep[0] = i;
				so_long->enemy->ep[1] = line;
				break ;
			}
			i++;
		}
		if (so_long->map[line][i] == '0' && so_long->map[line][i + 1] == '0')
			break ;
		line++;
	}
	so_long->enemy->sign = 1;
}
