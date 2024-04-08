/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:19:02 by djin              #+#    #+#             */
/*   Updated: 2024/04/08 14:53:00 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	wall_check(char *line, int max_len, int line_count, int total_line)
{
	int		i;

	i = 0;
	if (line_count == 0 || line_count == total_line)
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
	int		total_line;
	char	*line;

	if (line_count == -1)
		return (false);
	total_line = line_count;
	line = "";
	max_len = ft_strlen(so_long->lst_map->content) - 1;
	tmp = so_long->lst_map;
	while (line_count-- && tmp->next)
	{
		line = ft_strdup(tmp->content);
		if (!wall_check(line, max_len, line_count, total_line))
		{
			free(line);
			return (false);
		}
		free(line);
		tmp = tmp->next;
	}
	return (true);
}

bool	check_char_in_map(t_so_long *so_long)
{
	int		i;
	int		line;

	line = 0;
	while (so_long->map[line])
	{
		i = 0;
		while (so_long->map[line][i])
		{
			if (
				!(so_long->map[line][i] != '1' || so_long->map[line][i] != '0' \
				|| so_long->map[line][i] != 'P' || so_long->map[line][i] != 'E' \
				|| so_long->map[line][i] != 'C' || so_long->map[line][i] != '*')
			)
				return (false);
			i++;
		}
		line++;
	}
	return (true);
}
