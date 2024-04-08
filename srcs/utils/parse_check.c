/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:01:33 by djin              #+#    #+#             */
/*   Updated: 2024/04/08 14:39:22 by geibo            ###   ########.fr       */
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
	t_char	char_l;
	t_list	*new_node;

	char_l.line_count = 0;
	char_l.line = "";
	while (char_l.line != NULL)
	{
		char_l.line = get_next_line(so_long->map_fd);
		char_l.line_count++;
		if (!char_l.line)
		{
			if (so_long->gw == -1)
				return (-1);
			break ;
		}
		new_node = ft_lstnew(ft_strdup(char_l.line));
		if (so_long->gw == -1)
			so_long->gw = ft_strlen(char_l.line) - 1;
		if (so_long->lst_map == NULL)
			so_long->lst_map = new_node;
		else
			ft_lstadd_back(&so_long->lst_map, new_node);
		free(char_l.line);
	}
	return (char_l.line_count);
}
