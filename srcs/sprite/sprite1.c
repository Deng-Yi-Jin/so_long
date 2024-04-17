/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:05:00 by geibo             #+#    #+#             */
/*   Updated: 2024/04/16 18:44:26 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*path_sprite(char *sprite_name, int nb)
{
	char	*nbr;
	char	*path;
	char	*path2;

	nbr = ft_itoa(nb);
	path = ft_strjoin("./assets/", sprite_name);
	path2 = ft_strjoin(path, "/");
	free(path);
	path = ft_strjoin(path2, sprite_name);
	free(path2);
	path2 = ft_strjoin(path, "_");
	free(path);
	path = ft_strjoin(path2, nbr);
	free(path2);
	path2 = ft_strjoin(path, ".xpm");
	free(path);
	free(nbr);
	return (path2);
}

static void	load_sprite_type_xpm(int i, char *p, int sprite_type,
t_so_long *so_long)
{
	int	d;

	d = BPX;
	if (sprite_type == 2)
		so_long->ms[i - 1] = mlx_xpm_file_to_image(so_long->mlx, p, &d, &d);
}

static void	load_sprite(char *sprite_name, int nb_sprite, int sprite_type, \
t_so_long *so_long)
{
	int		i;
	char	*path;
	int		fd;

	i = 0;
	while (i++ < nb_sprite)
	{
		path = path_sprite(sprite_name, i - 1);
		fd = open(path, O_RDONLY);
		if (fd < 0)
			error_free("Fail to open sprite file", so_long);
		close(fd);
		load_sprite_type_xpm(i, path, sprite_type, so_long);
		free(path);
	}
}

void	init_sprite(t_so_long *so_long)
{
	load_sprite("monster", 22, 2, so_long);
}
