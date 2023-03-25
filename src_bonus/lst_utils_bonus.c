/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:01:31 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 16:26:28 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

t_pile	*lstnew(int content)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	freelst(t_pile **lst)
{
	t_pile	*tmp;

	while ((*lst) != NULL)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
	free(*lst);
}

t_pile	*lstlast(t_pile *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*buf;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	buf = *lst;
	buf = lstlast(buf);
	buf->next = new;
}

void	lstadd_front(t_pile **pile, t_pile *pile2)
{
	if (!pile || !pile2)
		return ;
	pile2->next = (*pile);
	(*pile) = pile2;
}
