/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:58:06 by geibo             #+#    #+#             */
/*   Updated: 2024/04/17 22:29:17 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_lst(t_so_long *so_long, char *line)
{
	so_long->lst_map = ft_lstnew(ft_strdup(line));
	so_long->lst_map->head = so_long->lst_map;
}

bool	check_char(t_so_long *so_long)
{
	int	i;
	int	line;

	line = 0;
	while (so_long->map[line])
	{
		i = 0;
		while (so_long->map[line][i])
		{
			if (
				!(so_long->map[line][i] == '1' || so_long->map[line][i] == '0'
				|| so_long->map[line][i] == 'P' || so_long->map[line][i] == 'E'
				|| so_long->map[line][i] == 'C' || so_long->map[line][i] == 'M'
				|| so_long->map[line][i] == '*'
				|| (i == so_long->gw - 1 && so_long->map[line][i] == '\n'))
			)
				return (false);
			if (i == so_long->gw - 1 && so_long->map[line][i] != '\n')
				return (false);
			i++;
		}
		line++;
	}
	return (true);
}

void	put_img(t_so_long *so_long, int x, int y, void *img)
{
	mlx_put_image_to_window(so_long->mlx, so_long->win, img, \
	x * BPX, y * BPX);
}

void	put_img_to_map2(t_so_long *so_long, int x, int y)
{
	if (so_long->map[y][x] == 'P')
	{
		put_img(so_long, x, y, so_long->sprite_img.floor);
		put_img(so_long, x, y, so_long->player->right);
		so_long->player->pp[0] = x;
		so_long->player->pp[1] = y;
	}
	else if (so_long->map[y][x] == 'E')
		put_img(so_long, x, y, so_long->sprite_img.exit);
	else if (so_long->map[y][x] == 'C')
	{
		put_img(so_long, x, y, so_long->sprite_img.floor);
		put_img(so_long, x, y, so_long->sprite_img.coin);
	}
}

void	put_img_to_map(t_so_long *so_long)
{
	int	i;
	int	line;

	line = 0;
	while (so_long->map[line])
	{
		i = 0;
		while (so_long->map[line] && so_long->map[line][i])
		{
			if (so_long->map[line][i] == '1')
				put_img(so_long, i, line, so_long->sprite_img.wall);
			else if (so_long->map[line][i] == '0')
				put_img(so_long, i, line, so_long->sprite_img.floor);
			put_img_to_map2(so_long, i, line);
			i++;
		}
		line++;
	}
	mlx_string_put(so_long->mlx, so_long->win, 10, 10, 0x00FFFFFF, "Step: ");
	mlx_string_put(so_long->mlx, so_long->win, 10, 30, 0x00FFFFFF, "0");
}
