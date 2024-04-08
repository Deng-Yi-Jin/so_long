/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:20 by djin              #+#    #+#             */
/*   Updated: 2024/04/08 16:48:46 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	convert_lst_to_map(t_so_long *so_long, int line_count)
{
	t_list	*current_line;
	int		i;

	so_long->gh = ft_lstsize(so_long->lst_map);
	if (line_count < 3)
		return (false);
	so_long->map = ft_calloc(line_count + 1, sizeof(char *));
	if (!so_long->map)
		return (false);
	current_line = so_long->lst_map;
	i = 0;
	while (current_line)
	{
		so_long->map[i] = ft_strdup(current_line->content);
		if (!so_long->map[i])
			return (false);
		i++;
		current_line = current_line->next;
	}
	so_long->gw = ft_strlen(so_long->map[0]);
	if (so_long->gw < 3)
		return (false);
	return (true);
}

bool	init_map_cord(t_so_long *so_long)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(so_long->map[0]) - 1;
	y_len = ft_lstsize(so_long->lst_map);
	so_long->map_cord = ft_calloc(1, sizeof(t_map_cord));
	if (!so_long->map_cord)
		return (false);
	so_long->map_cord->x = (WINDOW_WIDTH / 2) - (x_len * BPX / 2);
	so_long->map_cord->y = (WINDOW_HEIGHT / 2) - (y_len * BPX / 2);
	return (true);
}

bool	init_map_img(t_so_long *so_long)
{
	int	width;
	int	height;

	so_long->map_img.wall = mlx_xpm_file_to_image(so_long->mlx, \
	"./sprites/Fence.xpm", &width, &height);
	return (true);
}
