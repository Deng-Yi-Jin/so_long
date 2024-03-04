/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:19:02 by djin              #+#    #+#             */
/*   Updated: 2024/03/04 15:25:07 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	wall_check(char *line, int max_len, int line_count)
{
	int	i;

	i = 0;
	if (line_count == max_len || line_count == 1)
	{
		while (line[i])
		{
			if (line[i] != '1')
				return (false);
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[max_len - 1] != '1')
			return (false);
	}
	return (true);
}

bool	lst_line_wall_check(t_so_long *so_long, int line_count)
{
	t_list	*tmp;
	int		max_len;
	char	*line;

	line = "";
	max_len = ft_strlen(so_long->lst_map->content);
	tmp = so_long->lst_map;
	while (line_count--)
	{
		line = ft_strdup(tmp->content);
		if (!wall_check(line, max_len, line_count))
		{
			free(line);
			return (false);
		}
		free(line);
		tmp = tmp->next;
	}
	return (true);
}
