/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:57:35 by djin              #+#    #+#             */
/*   Updated: 2024/04/11 15:27:37 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_wall(t_list *map)
{
	char	*first;
	int		i;

	i = 0;
	first = ;
	if (!first)
		return (false);
	while (first[i])
	{
		if (first[i] != '1')
		{
			free(first);
			return (false);
		}
		i++;
	}
	free(first);
	return (true);
}

bool	check_inside(t_list *map)
{
	t_list	*tmp;
	// char	*line;

	tmp = map;
	// while (tmp)
	// {
	// 	// line = tmp->content;
	// 	// while (*line)
	// 	// {
	// 	// 	if (!ft_strchr("01CEP", *line))
	// 	// 		return (false);
	// 	// 	line++;
	// 	// }
	// 	// tmp = tmp->next;
	// }
	return (true);
}
