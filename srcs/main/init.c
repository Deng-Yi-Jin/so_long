/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:01:26 by geibo             #+#    #+#             */
/*   Updated: 2024/04/09 22:37:28 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(int argc, char **argv, t_so_long *so_long)
{
	if (!map_is_valid(argv[1], argc))
	{
		ft_putstr_fd("Error\nInvalid map file\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!open_map(so_long, argv[1]))
	{
		ft_putstr_fd("Error\nFail to open map file\n", 2);
		exit(EXIT_FAILURE);
	}
	
}
