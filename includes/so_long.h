/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:27:23 by djin              #+#    #+#             */
/*   Updated: 2024/03/26 13:53:25 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
// # include <mlx.h>
# include "../lib/mlx_linux/mlx.h"
# include "libft.h"
# include "ft_printf.h"

# define BUFFER_SIZE 42
# define BPX 100
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define FAIL_MAP "Invalid map"
# define WALL_FAIL "Invalid wall"
# define CHAR_FAIL "Invalid character"
# define FAIL_IMG "Fail to generate image"

# define TITLE "so_long"

typedef struct s_player
{
	int	pp[2];
	int	step;
}	t_player;

typedef struct s_map_cord
{
	int		x;
	int		y;
}	t_map_cord;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	int			map_fd;
	char		**map;
	t_map_cord	*map_cord;
	t_list		*lst_map;
	t_player	*player;
}	t_so_long;

//get_next_line
char	*get_next_line(int fd);

//initialize
void	init_s_so_long(t_so_long *so_long, char **argv);
void	init_map(int argc, char **argv, t_so_long *so_long);

//parse_check
bool	argc_check(int argc);
bool	open_map(char *argv, t_so_long *so_long);
int		add_lst_map(t_so_long *so_long);

//error
void	error(char *message);

//map_utils
bool	convert_lst_to_map(t_so_long *so_long, int line_count);
bool	init_map_cord(t_so_long *so_long);
bool	check_char_in_map(t_so_long *so_long);
bool	image_gen(t_so_long *so_long);

//map_checker
bool	lst_line_wall_check(t_so_long *so_long, int line_count);
#endif