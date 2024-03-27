/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:30:53 by geibo             #+#    #+#             */
/*   Updated: 2024/03/27 14:38:38 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_so_long so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < so_long.gh)
	{
		j = 0;
		while (j < so_long.gw)
		{
			ft_printf("%c", so_long.map[i][j]);
			j++;
		}
		i++;
	}
	ft_printf("\n");
}
