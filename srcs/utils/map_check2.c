/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:20:05 by geibo             #+#    #+#             */
/*   Updated: 2024/04/18 14:32:54 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_same_length(t_so_long *so_long)
{
	int	len;
	int	i;

	len = ft_strlen(so_long->map[0]) - 2;
	printf("len: %d\n", len);
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
			if (ft_strlen(so_long->map[i]) - 1 != len)
				return (false);
		}
		i++;
	}
	return (true);
}
