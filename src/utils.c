/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:56:22 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 14:06:20 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_in_two(t_pile **stacka)
{
	t_pile	*tmp;

	tmp = (*stacka)->next;
	if ((*stacka)->content > tmp->content)
		swap_a(stacka, 0);
}

void	sort_in_tree(t_pile **stacka)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp2 = (*stacka)->next->next;
	tmp = (*stacka)->next;
	if ((*stacka)->content == 1 && tmp->content == 2 && tmp2->content == 0)
		rra(stacka, 8);
	if ((*stacka)->content == 2 && tmp->content == 1 && tmp2->content == 0)
	{
		swap_a(stacka, 0);
		rra(stacka, 8);
	}
	if ((*stacka)->content == 1 && tmp->content == 0 && tmp2->content == 2)
		swap_a(stacka, 0);
	if ((*stacka)->content == 2 && tmp->content == 0 && tmp2->content == 1)
		rotate(stacka, 5);
	if ((*stacka)->content == 0 && tmp->content == 2 && tmp2->content == 1)
	{
		swap_a(stacka, 0);
		rotate(stacka, 5);
	}
}

void	sort_in_four(t_pile **stacka, t_pile **stackb)
{
	int		i;
	t_pile	*next;
	t_pile	*tmp;

	i = 0;
	tmp = *stacka;
	while (tmp != NULL)
	{
		if (tmp->content == 3)
		{
			push_beginstack(stacka, stackb, i, 4);
			return ;
		}
		i++;
		next = tmp->next;
		tmp = next;
	}
	sort_in_tree(stacka);
}

void	norm_sorttab(t_pile **stacka, t_pile **stackb, t_data *data, int len)
{
	data->cpt = 0;
	while (data->pivot <= len)
	{
		if (data->pivot != 0)
			data->equalpivot += data->pivotmp;
		data->pivot += data->pivotmp;
		while (data->cpt < data->pivot)
		{	
			data->tmp2 = ft_stacksize(stacka);
			data->tmp = pos_contentwo(stacka, data->equalpivot, data->pivot);
			push_beginstack(stacka, stackb, data->tmp, data->tmp2);
			if ((*stackb)->content <= (data->pivot - (data->pivotmp / 2)))
				rotate(stackb, 6);
			data->cpt++;
		}
	}
}

int	pos_content(t_pile **a, int i)
{
	t_pile	*tmp;
	t_pile	*next;
	int		pos;

	pos = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->content == i)
			return (pos);
		pos++;
		next = tmp->next;
		tmp = next;
	}
	return (0);
}
