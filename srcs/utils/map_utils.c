/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:08:35 by geibo             #+#    #+#             */
/*   Updated: 2024/04/11 16:43:25 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_is_valid(char *argv, int argc)
{
	if (!argv || ft_strcmp(ft_strrchr(argv, '.'), ".ber")
		|| argc != 2)
		return (false);
	return (true);
}

bool	open_map(t_so_long *so_long, char *argv)
{
	char	*path;

	path = ft_strdup(argv);
	if (!path)
		return (false);
	if (ft_strcmp(ft_strrchr(path, '.'), ".ber") != 0)
	{
		free(path);
		return (false);
	}
	so_long->map_fd = open(path, O_RDONLY);
	free(path);
	if (so_long->map_fd < 0)
		return (false);
	return (true);
}

int	parse_map(t_so_long *so_long)
{
	char	*line;
	char	line_count;

	line_count = 0;
	line = "";
	while (line)
	{
		line = get_next_line(so_long->map_fd);
		line_count++;
		if (line == NULL)
		{
			if (so_long->gw == -1)
				return (-1);
			break ;
		}
		if (so_long->gw == -1)
			so_long->gw = ft_strlen(line);
		if (so_long->lst_map == NULL)
		{
			so_long->lst_map = ft_lstnew(ft_strdup(line));
			so_long->lst_map->head = so_long->lst_map;
		}
		else
			ft_lstadd_back(&so_long->lst_map, ft_lstnew(ft_strdup(line)));
		free(line);
		so_long->lst_map->tail = ft_lstlast(so_long->lst_map);
	}
	return (line_count);
}

bool	check_map(t_so_long *so_long, int line_count)
{
	t_node	*current_node;
	char	*trim;
	int		i;

	i = 0;
	current_node = so_long->lst_map->head;
	while (current_node)
	{
		trim = ft_strtrim(current_node->content, "\n");
		if (ft_strlen(trim) != (so_long->gw - 1))
		{
			free(trim);
			return (false);
		}
		free(trim);
		if (i == 0 || i == line_count - 1)
		{
			if (!check_wall(current_node))
				return (false);
		}
		else
		{
			if (!check_inside(current_node))
				return (false);
		}
		current_node = current_node->next;
		i++;
	}
	return (true);
}
