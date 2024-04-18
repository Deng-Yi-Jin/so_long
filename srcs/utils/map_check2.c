/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:20:05 by geibo             #+#    #+#             */
/*   Updated: 2024/04/18 14:03:56 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_same_length(t_so_long *so_long)
{
	int	len;
	int	i;

	len = ft_strlen(so_long->map[0]) - 2;
	i = 0;
	while (so_long->map[i])
	{
		if (so_long->map[i][len + 1] == '\n')
		{
			if (ft_strlen(so_long->map[i]) - 2 != len)
				return (false);
		}
		else
		{
			if (ft_strlen(so_long->map[i]) != len)
				return (false);
		}
		i++;
	}
	return (true);
}
