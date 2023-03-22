/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:28:27 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/04 15:06:18 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pos_contentwo(t_pile **a, int i, int j)
{
	t_pile	*tmp;
	t_pile	*next;
	int		pos;

	pos = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->content >= i && tmp->content < j)
			return (pos);
		pos++;
		next = tmp->next;
		tmp = next;
	}
	return (0);
}

void	sort_in_five(t_pile **stacka, t_pile **stackb)
{
	int		i;
	t_pile	*tmp;

	i = pos_content(stacka, 4);
	push_beginstack(stacka, stackb, i, 5);
	i = pos_content(stacka, 3);
	push_beginstack(stacka, stackb, i, 4);
	sort_in_tree(stacka);
	tmp = (*stackb)->next;
	if ((*stackb)->content > tmp->content)
		swap_b(stackb, 1);
	push(stackb, stacka, 3);
	rotate(stacka, 5);
	push(stackb, stacka, 3);
	rotate(stacka, 5);
}

int	nbarg(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	print_instru(int i)
{
	if (i == 0)
		ft_printf("%s", "sa");
	else if (i == 1)
		ft_printf("%s", "sb");
	else if (i == 2)
		ft_printf("%s", "ss");
	else if (i == 3)
		ft_printf("%s", "pa");
	else if (i == 4)
		ft_printf("%s", "pb");
	else if (i == 5)
		ft_printf("%s", "ra");
	else if (i == 6)
		ft_printf("%s", "rb");
	else if (i == 7)
		ft_printf("%s", "rr");
	else if (i == 8)
		ft_printf("%s", "rra");
	else if (i == 9)
		ft_printf("%s", "rrb");
	else if (i == 10)
		ft_printf("%s", "rrr");
	else if (i == 11)
		return ;
	ft_printf("%c", '\n');
}

int	pos_pivot(t_pile **a, int pivot, int equalpivot)
{
	t_pile	*tmp;
	t_pile	*next;
	int		pos;

	pos = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->content >= equalpivot && tmp->content < pivot)
			return (pos);
		pos++;
		next = tmp->next;
		tmp = next;
	}
	return (0);
}
