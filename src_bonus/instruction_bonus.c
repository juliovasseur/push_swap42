/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:20:49 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 16:20:51 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	swap_a(t_pile **stacka, int i)
{
	t_pile		*tmp;
	int			tmp2;

	tmp = *stacka;
	if (tmp == NULL || tmp->next == NULL)
		return ;
	tmp2 = tmp->next->content;
	tmp->next->content = tmp->content;
	tmp->content = tmp2;
	*stacka = tmp;
	print_instru(i);
	return ;
}

void	swap_b(t_pile **stackb, int i)
{
	t_pile		*tmp;
	int			tmp2;

	tmp = *stackb;
	if (tmp == NULL || tmp->next == NULL)
		return ;
	tmp2 = tmp->next->content;
	tmp->next->content = tmp->content;
	tmp->content = tmp2;
	*stackb = tmp;
	print_instru(i);
	return ;
}

void	swap_ss(t_pile **stacka, t_pile **stackb, int i)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_pile	*tmp3;

	if ((*stacka)->size > 1 && (*stackb)->size > 1)
	{
		tmp2 = (*stacka)->next;
		tmp = *stacka;
		tmp3 = (*stacka)->next->next;
		*stacka = tmp2;
		(*stacka)->next = tmp;
		(*stacka)->next->next = tmp3;
		tmp2 = (*stackb)->next;
		tmp = *stackb;
		tmp3 = (*stackb)->next->next;
		*stackb = tmp2;
		(*stackb)->next = tmp;
		(*stackb)->next->next = tmp3;
		print_instru(i);
	}
	else
		return ;
}

void	push(t_pile **begin, t_pile **stackpush, int j)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	(void)stackpush;
	if (*begin == NULL)
		return ;
	tmp = (*begin)->next;
	tmp2 = *stackpush;
	(*stackpush) = (*begin);
	(*stackpush)->next = tmp2;
	*begin = tmp;
	print_instru(j);
}

void	rotate(t_pile **stack, int i)
{
	t_pile	*first;
	t_pile	*last;
	t_pile	*stacktmp;
	int		tmp;

	tmp = ft_stacksize(stack);
	if (tmp == 1 || tmp == 0)
		return ;
	if (tmp == 2)
		swap_a(stack, i);
	stacktmp = *stack;
	if (!(stacktmp))
		return ;
	first = stacktmp;
	stacktmp = stacktmp->next;
	last = stacktmp;
	if (!(last->next))
		return ;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*stack = stacktmp;
	print_instru(i);
	return ;
}
