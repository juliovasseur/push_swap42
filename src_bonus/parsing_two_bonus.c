/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:42:09 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 16:19:14 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	max_int(t_data *data)
{
	data->tmp = 0;
	while (data->tab[data->tmp])
	{
		if ((ft_atoi(data->tab[data->tmp]) == 0
				|| ft_atoi(data->tab[data->tmp]) == -1)
			&& (ft_atol(data->tab[data->tmp]) == 1000))
			return (0);
		data->tmp++;
	}
	return (1);
}

int	verif_vide(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ')
		{
			j++;
			if (argv[i][j] == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	order_or_not(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (data->tab[j])
	{
		if (ft_atoi(data->tab[i]) > ft_atoi(data->tab[j]))
			return (1);
		i++;
		j++;
	}
	return (0);
}
