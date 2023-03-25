/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:22:06 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 17:10:53 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	malloc_int_tab(int **result, int len)
{
	*result = malloc(len * sizeof(int));
	if (!(*result))
		return (0);
	return (1);
}

int	check_error_and_free(t_data *data, char **argv)
{
	if (create_tab_arg(data) == 0)
	{
		write(2, "Error\n", 7);
		free(data);
		return (0);
	}
	else if (verif_all(data) == 0 || verif_vide(argv) == 0)
	{
		write(2, "Error\n", 7);
		free_splitdata(&data->tab);
		free(data);
		return (0);
	}
	else if (order_or_not(data) == 0)
	{
		free_splitdata(&data->tab);
		free(data);
		return (0);
	}
	return (1);
}

int	create_stacka(t_pile **stacka, int *stacktoken, int len)
{
	int	i;

	*stacka = lstnew(stacktoken[0]);
	if (!stacka)
	{
		free(stacktoken);
		return (0);
	}
	i = 1;
	while (i != len)
	{
		lstadd_back(stacka, lstnew(stacktoken[i]));
		if (!stacka)
		{
			free(stacktoken);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_algo(t_pile **stacka, t_pile **stackb, t_data *data)
{
	t_pile	*tmp;
	int		len;

	tmp = *stacka;
	len = ft_stacksize(&tmp);
	if (len == 2)
		sort_in_two(stacka);
	else if (len == 3)
		sort_in_tree(stacka);
	else if (len == 4)
	{
		sort_in_four(stacka, stackb);
		sort_in_tree(stacka);
		push(stackb, stacka, 3);
		rotate(stacka, 5);
	}
	else if (len == 5)
	{
		sort_in_five(stacka, stackb);
	}
	else
	{
		sort_in_tab(stacka, stackb, data, len);
		sort_in_reverse_tab(stacka, stackb, data, len);
	}
}
