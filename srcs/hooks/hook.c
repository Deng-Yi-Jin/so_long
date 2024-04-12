/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:38:36 by geibo             #+#    #+#             */
/*   Updated: 2024/04/12 16:41:22 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		close_win(t_so_long *so_long)
{
	free_node(so_long->lst_map);
	free_map(so_long);
	free(so_long->player);
	exit(EXIT_SUCCESS);
	return(0);
}
