/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:01:33 by djin              #+#    #+#             */
/*   Updated: 2024/03/21 15:16:21 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	argc_check(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (false);
	}
	return (true);
}

bool	open_map(char *argv, t_so_long *so_long)
{
	int	path_len;

	path_len = ft_strlen(argv);
	if (path_len < 4)
		return (false);
	if (ft_strcmp(&argv[path_len - 4], ".ber") != 0)
		return (false);
	so_long->map_fd = open(argv, O_RDONLY);
	if (so_long->map_fd < 0)
		return (false);
	return (true);
}

int	add_lst_map(t_so_long *so_long)
{
	char	*line;
	int		line_count;
	t_list	*new_node;

	line_count = 0;
	line = get_next_line(so_long->map_fd);
	while (line != NULL)
	{
		if (!line)
			break ;
		line_count++;
		new_node = ft_lstnew(ft_strdup(line));
		if (new_node == NULL)
		{
			free(line);
			return (-1);
		}
		if (so_long->lst_map == NULL)
			so_long->lst_map = new_node;
		else
			ft_lstadd_back(&so_long->lst_map, new_node);
		free(line);
		line = get_next_line(so_long->map_fd);
	}
	return (line_count);
}
