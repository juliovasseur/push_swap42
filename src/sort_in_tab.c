/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:19:12 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/04 18:00:25 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	tokenize(t_data *data, t_pile **stacka)
{
	int	i;
	int	j;
	int	tmp;
	int	*result;
	int	len;

	len = nbarg(data->tab);
	result = malloc(len * sizeof(int));
	i = 0;
	tmp = len;
	while (i < len)
	{
		j = 0;
		tmp = len - 1;
		while (j < len)
		{
			if (ft_atoi(data->tab[i]) < ft_atoi(data->tab[j]))
				tmp--;
			j++;
		}
		result[i] = tmp;
		i++;
	}
	create_stacka(stacka, result, len);
	free(result);
}

void	push_beginstack(t_pile **stacka, t_pile **stackb, int pos, int len)
{
	int	i;

	i = len / 2;
	if (pos > i)
	{
		while (pos != len)
		{
			rra(stacka, 8);
			pos++;
		}
		i++;
	}
	else
	{
		while (pos != 0)
		{
			rotate(stacka, 5);
			pos--;
		}
	}
	push(stacka, stackb, 4);
}

void	reverse_beginstack(t_pile **stacka, t_pile **stackb, int pos, int len)
{
	int	i;

	i = len / 2;
	if (pos > i)
	{
		while (pos != len)
		{
			rra(stacka, 9);
			pos++;
		}
		i++;
	}
	else
	{
		while (pos != 0)
		{
			rotate(stacka, 6);
			pos--;
		}
	}
	push(stacka, stackb, 3);
}

void	sort_in_tab(t_pile **stacka, t_pile **stackb, t_data *data, int len)
{
	data->equalpivot = 0;
	data->pivot = 0;
	if (len == 500)
		data->pivotmp = len / 10;
	else
		data->pivotmp = len / 5;
	norm_sorttab(stacka, stackb, data, len);
}

void	sort_in_reverse_tab(t_pile **a, t_pile **b, t_data *data, int len)
{
	data->pivot = len - 1;
	while (data->pivot >= 0)
	{
		data->cpt = ft_stacksize(b) / 2 + 2;
		data->tmp2 = ft_stacksize(b);
		data->tmp = pos_content(b, data->pivot);
		data->tmp3 = pos_content(b, data->pivot - 1);
		if ((data->tmp > data->cpt && data->tmp3 > data->tmp)
			|| (data->tmp < data->cpt && data->tmp3 < data->tmp)
			|| (data->tmp < data->cpt && data->tmp3 > data->cpt
				&& data->tmp2 - data->tmp3 < data->tmp)
			|| (data->tmp > data->cpt && data->tmp3 < data->cpt
				&& data->tmp2 - data->tmp > data->tmp3))
		{
			reverse_beginstack(b, a, data->tmp3, data->tmp2);
			data->tmp2 = ft_stacksize(b);
			data->tmp = pos_content(b, data->pivot);
			data->pivot--;
			reverse_beginstack(b, a, data->tmp, data->tmp2);
			swap_a(a, 0);
		}
		else
			reverse_beginstack(b, a, data->tmp, data->tmp2);
		data->pivot--;
	}
}
