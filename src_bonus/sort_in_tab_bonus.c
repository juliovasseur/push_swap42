/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:19:12 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 17:13:06 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	malloc_int_tab(int **result, int len)
{
	*result = malloc(len * sizeof(int));
	if (!(*result))
		return (0);
	return (1);
}

int	tokenize(t_data *data, t_pile **stacka)
{
	int	i;
	int	j;
	int	tmp;
	int	*result;
	int	len;

	i = 0;
	len = nbarg(data->tab);
	if (malloc_int_tab(&result, len) == 0)
		return (0);
	while (i < len)
	{
		j = 0;
		tmp = len - 1;
		while (j < len)
		{
			if (ft_atoi(data->tab[i]) < ft_atoi(data->tab[j++]))
				tmp--;
		}
		result[i++] = tmp;
	}
	if (create_stacka(stacka, result, len) == 0)
		return (0);
	free(result);
	return (1);
}
