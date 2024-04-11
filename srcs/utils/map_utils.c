/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:08:35 by geibo             #+#    #+#             */
/*   Updated: 2024/04/09 22:38:27 by geibo            ###   ########.fr       */
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

	path = ft_strjoin("./maps/", argv);
	so_long->map_fd = open(path, O_RDONLY);
	free(path);
	if (so_long->map_fd < 0)
		return (false);
}

bool	read_map(t_so_long *so_long)
{
	char	*line;

	
}
