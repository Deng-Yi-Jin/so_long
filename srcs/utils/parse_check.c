/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:01:33 by djin              #+#    #+#             */
/*   Updated: 2024/03/20 17:04:48 by geibo            ###   ########.fr       */
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

	path_len = ft_strlen(argv) + 1;
	if (!ft_strncmp(&argv[path_len - 4], ".ber", 4))
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
	bool	line_check;
	t_list	*new_node;

	if (so_long == NULL)
		return (-1);
	line_check = true;
	line = "";
	line_count = 0;
	while (line_check == true || line != NULL)
	{
		if (line_check == true)
			line_check = false;
		line = get_next_line(so_long->map_fd);
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
			so_long->lst_map = ft_lstnew(ft_strdup(line));
		else
			ft_lstadd_back(&so_long->lst_map, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	return (line_count);
}
