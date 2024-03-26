/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:39:16 by djin              #+#    #+#             */
/*   Updated: 2024/03/21 12:37:39 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*newnode;

	if (!lst || !new)
		return ;
	newnode = *lst;
	if (newnode != NULL)
	{
		newnode = ft_lstlast(newnode);
		newnode -> next = new;
		new -> prev = newnode;
	}
	else
		*lst = new;
}
