/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:27:23 by djin              #+#    #+#             */
/*   Updated: 2024/04/18 14:35:19 by djin             ###   ########.fr       */
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
# include <mlx.h>
# include "sprite_type.h"
// # include "../lib/mlx_linux/mlx.h"
# include "libft.h"
# include "ft_printf.h"

# define KEYPRESS 2
# define DESTROY 17
# define W 13
# define A 0
# define D 2
# define S 1
# define ESC 53

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

// # define UP 119
// # define DOWN 115
// # define LEFT 97
// # define RIGHT 100
// # define ESC 65307

# define BUFFER_SIZE 42
# define BPX 50
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
	int		pp[2];
	int		step;
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}	t_player;

typedef struct s_enemy
{
	void	**img;
	int		ep[2];
	int		frame;
	int		img_index;
	int		sign;
}	t_enemy;

typedef struct s_map_img
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*exit1;
	void	*coin;
}	t_map_img;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	int			map_fd;
	int			gh;
	int			gw;
	int			exit_status;
	char		**map;
	t_map_img	sprite_img;
	t_node		*lst_map;
	t_enemy		*enemy;
	t_player	*player;
}	t_so_long;

//get_next_line
char	*get_next_line(int fd);

//initialize
void	init_s_so_long(t_so_long *so_long);
void	init_map(int argc, char **argv, t_so_long *so_long);
void	init_image(t_so_long *so_long);
void	init_enemy_img(t_so_long *so_long);

//map_check
bool	check_wall(t_node *map);
bool	check_inside(t_node *map);
int		map_height(t_node *map);
bool	check_collectible(t_so_long *so_long);
bool	check_column_row(t_so_long *so_long);

//map_check2
bool	check_same_length(t_so_long *so_long);

//error
void	error(char *str);
void	error_free(char *str, t_so_long *so_long);

//map_utils
bool	map_is_valid(char *argv, int argc);
bool	open_map(t_so_long *so_long, char *argv);
int		parse_map(t_so_long *so_long);
bool	check_map(t_so_long *so_long, int line_count);
bool	convert_node(t_so_long *so_long);

//map_utils2
bool	check_char(t_so_long *so_long);
void	put_img(t_so_long *so_long, int x, int y, void *img);
void	put_img_to_map(t_so_long *so_long);
void	add_lst(t_so_long *so_long, char *line);

//enemy
void	get_enemy_pos(t_so_long *so_long);

//free
void	free_node(t_node *node);
void	free_map(t_so_long *so_long);

// void	load_sprite_png(t_so_long *so_long, char *path, int s_type);
void	load_sprite_xpm(t_so_long *so_long, char *path, int s_type);

//game
void	game_over(t_so_long *so_long);
void	game_win(t_so_long *so_long);
void	move_collect(t_so_long *so_long, int x, int y);

//debug
void	print_map(t_so_long *so_long);

//hook
int		key_hook(int keycode, t_so_long *so_long);
int		close_win(t_so_long *so_long);
int		animation(t_so_long *so_long);

//movement
void	up(t_so_long *so_long);
void	down(t_so_long *so_long);
void	left(t_so_long *so_long);
void	right(t_so_long *so_long);

#endif