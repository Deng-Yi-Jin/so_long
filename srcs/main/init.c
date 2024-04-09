/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:03:07 by djin              #+#    #+#             */
/*   Updated: 2024/04/08 23:59:39 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_s_so_long(t_so_long *so_long, char **argv)
{
	(void)argv;
	so_long->mlx = mlx_init();
	so_long->gw = -1;
	so_long->gh = -1;
	so_long->player = ft_calloc(1, sizeof(t_player));
	so_long->win = mlx_new_window(so_long->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
	TITLE);
	so_long->lst_map = NULL;
}

void	init_map(int argc, char **argv, t_so_long *so_long)
{
	int		line_count;

	if (!argc_check(argc))
		exit(EXIT_FAILURE);
	if (!open_map(argv[1], so_long))
		error(FAIL_MAP);
	line_count = add_lst_map(so_long);
	if (!lst_line_wall_check(so_long, line_count))
		error(WALL_FAIL);
	if (!convert_lst_to_map(so_long, line_count))
		error(FAIL_MAP);
	if (!check_char_in_map(so_long))
		error(CHAR_FAIL);
	if (!init_map_cord(so_long))
		error(FAIL_MAP);
	printf("OK\n");
}

bool	init_player(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'P')
			{
				so_long->player->pp[0] = j * BPX;
				so_long->player->pp[1] = i * BPX - 1;
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
