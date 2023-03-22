/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 03:29:53 by jules             #+#    #+#             */
/*   Updated: 2023/03/02 18:34:23 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_rr(t_pile **stack, t_pile **stackb, int i)
{
	rotate(stack, i);
	rotate(stackb, i);
	print_instru(i);
	return ;
}

void	rra(t_pile **stack, int i)
{
	t_pile	*last;
	t_pile	*first;
	t_pile	*stacktmp;

	stacktmp = *stack;
	if (!(stacktmp && stacktmp->next))
		return ;
	last = stacktmp;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	last->next = stacktmp;
	first->next = NULL;
	*stack = last;
	print_instru(i);
	return ;
}

void	rrb(t_pile **stack, int i)
{
	t_pile	*last;
	t_pile	*first;
	t_pile	*stacktmp;

	stacktmp = *stack;
	if (!(stacktmp && stacktmp->next))
		return ;
	last = stacktmp;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	last->next = stacktmp;
	first->next = NULL;
	*stack = last;
	print_instru(i);
	return ;
}

void	rrr(t_pile **stack, t_pile **stackb, int i)
{
	rra(stack, i);
	rrb(stackb, i);
	print_instru(i);
	return ;
}

int	ft_stacksize(t_pile **stack)
{
	int		cpt;
	t_pile	*tmp;

	cpt = 0;
	tmp = *stack;
	if (!tmp)
		return (0);
	while (tmp != NULL)
	{
		tmp = tmp->next;
		cpt++;
	}
	return (cpt);
}
