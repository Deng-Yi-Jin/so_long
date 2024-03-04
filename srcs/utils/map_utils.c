/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:20 by djin              #+#    #+#             */
/*   Updated: 2024/03/04 15:19:26 by djin             ###   ########.fr       */
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
