/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:12:14 by geibo             #+#    #+#             */
/*   Updated: 2024/03/26 14:29:14 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprite_type(char *sprite_name, t_so_long *so_long)
{
	int	i;
	int	j;

	j = 0;
	if (ft_strcmp(sprite_name, "Wall") == 0)
	{
		while (so_long->map[j])
		{
			i = 0;
			while (so_long->map[j][i])
			{
				if (so_long->map[j][i] == '1')
				{
					
				}
				i++;
			}
		}
			
	}
}

void	load_sprite(t_so_long *so_long)
{
	load_sprite_type("Wall", so_long);
}
