/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:01:20 by geibo             #+#    #+#             */
/*   Updated: 2024/04/12 17:03:21 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->gh)
	{
		printf("%s", so_long->map[i]);
		i++;
	}
	printf("\n");
}
