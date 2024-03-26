/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:20 by djin              #+#    #+#             */
/*   Updated: 2024/03/26 14:01:38 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	convert_lst_to_map(t_so_long *so_long, int line_count)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (line_count < 3)
		return (false);
	so_long->map = ft_calloc(line_count + 1, sizeof(char *));
	if (!so_long->map)
		return (false);
	tmp = so_long->lst_map;
	while (tmp)
	{
		so_long->map[i] = tmp->content;
		tmp = tmp->next;
	}
	return (true);
}

bool	init_map_cord(t_so_long *so_long)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(so_long->map[0]);
	y_len = ft_lstsize(so_long->lst_map);
	so_long->map_cord = ft_calloc(1, sizeof(t_map_cord));
	if (!so_long->map_cord)
		return (false);
	so_long->map_cord->x = (WINDOW_WIDTH / 2) - (x_len * 32 / 2);
	so_long->map_cord->y = (WINDOW_HEIGHT / 2) - (y_len * 32 / 2);
	return (true);
}
