/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:57:35 by djin              #+#    #+#             */
/*   Updated: 2024/04/11 16:42:53 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_wall(t_node *map)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strdup(map->content);
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		if (line[i] != '1')
		{
			free(line);
			return (false);
		}
		i++;
	}
	free(line);
	return (true);
}

bool	check_inside(t_node *map)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_strdup(map->content);
	while (line[i])
	{
		if (line[0] != '1' || line[ft_strlen(line) - 2] != '1')
		{
			free(line);
			return (false);
		}
		if (line[i] == '0' || line[i] == 'P' || line[i] == 'E'
		|| line[i] == '\n' || line[i] == '1')
			i++;
		else
		{
			free(line);
			return (false);
		}
	}
	free(line);
	return (true);
}
