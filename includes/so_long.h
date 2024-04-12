/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:27:23 by djin              #+#    #+#             */
/*   Updated: 2024/04/12 17:02:56 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
// # include <mlx.h>
# include "sprite_type.h"
# include "../lib/mlx_linux/mlx.h"
# include "libft.h"
# include "ft_printf.h"

# define KEYPRESS 2
# define DESTROY 17
# define W 13
# define A 0
# define D 2
# define S 1
# define ESC 53

# define BUFFER_SIZE 42
# define BPX 100
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define TITLE "so_long"
# define FAIL_MAP "Invalid map"
# define WALL_FAIL "Invalid wall"
# define CHAR_FAIL "Invalid character"
# define FAIL_IMG "Fail to generate image"
# define OS "Linux"

# define TITLE "so_long"

typedef	struct s_char
{
	char	*line;
	int		line_count;
}	t_char;

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

typedef struct s_map_img
{
	void	*wall;
	void	*player;
	void	*coin;
}	t_map_img;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	int			map_fd;
	int			gh;
	int			gw;
	char		**map;
	t_map_img	map_img;
	t_map_cord	*map_cord;
	t_node		*lst_map;
	t_player	*player;
}	t_so_long;

//get_next_line
char	*get_next_line(int fd);

//initialize
void	init_s_so_long(t_so_long *so_long);
void	init_map(int argc, char **argv, t_so_long *so_long);

//map_check
bool	check_wall(t_node *map);
bool	check_inside(t_node *map);
int		map_height(t_node *map);

//error
void	error(char *str);
void	error_free(char *str, t_so_long *so_long);

//map_utils
bool	map_is_valid(char *argv, int argc);
bool	open_map(t_so_long *so_long, char *argv);
int		parse_map(t_so_long *so_long);
bool	check_map(t_so_long *so_long, int line_count);
bool	convert_node(t_so_long *so_long);

//free
void	free_node(t_node *node);
void	free_map(t_so_long *so_long);

//sprite1
void	load_sprite_type(t_so_long *so_long, char *path, int s_type);
char	*path_sprite(int type);
void	load_sprite(t_so_long *so_long, int s_type);
void	init_sprites(t_so_long *so_long);

//sprite_type
// void	load_sprite_png(t_so_long *so_long, char *path, int s_type);
void	load_sprite_xpm(t_so_long *so_long, char *path, int s_type);

//wall
void	draw_wall(t_so_long *so_long);
void	wall(t_so_long *so_long);

//player
void	player(t_so_long *so_long);

//debug
void	print_map(t_so_long *so_long);

//hook
int	key_hook(int keycode, t_so_long *so_long);
int	close_win(t_so_long *so_long);

//player
bool	init_player(t_so_long *so_long);

//free
void	free_map(t_so_long *so_long);

//movement
void	up(t_so_long *so_long);
void	down(t_so_long *so_long);
void	left(t_so_long *so_long);
void	right(t_so_long *so_long);

#endif