/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:05:52 by geibo             #+#    #+#             */
/*   Updated: 2024/04/12 17:04:38 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_so_long *map)
{
	int	i;

	i = 0;
	while (i < map->gh)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_node(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp->content);
		free(tmp);
	}
}
