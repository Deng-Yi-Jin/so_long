/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:49:11 by djin              #+#    #+#             */
/*   Updated: 2024/04/11 15:34:22 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew(void *content)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode -> content = content;
	newnode -> next = 0;
	return (newnode);
}
