/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:34:49 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 16:19:07 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	verif_if_consecutif_sign(t_data *data)
{
	data->tmp = 1;
	while (data->argment[data->tmp])
	{
		data->tmp2 = 0;
		while (data->argment[data->tmp][data->tmp2])
		{
			if (data->argment[data->tmp][data->tmp2] == '-' ||
			data->argment[data->tmp][data->tmp2] == '+')
			{
				if (data->argment[data->tmp][data->tmp2 + 1] == '-' ||
				data->argment[data->tmp][data->tmp2 + 1] == '+')
				{
					return (0);
				}
			}
			data->tmp2++;
		}
		data->tmp++;
	}
	return (1);
}

int	verif_sign(t_data *data)
{
	int	tmp;
	int	tmp2;

	tmp = 0;
	while (data->tab[tmp])
	{
		tmp2 = 0;
		if ((data->tab[tmp][tmp2] == '-' || data->tab[tmp][tmp2] == '+') &&
		ft_isdigit(data->tab[tmp][tmp2 + 1]) == 1)
				tmp2++;
		while (data->tab[tmp][tmp2])
		{
			if (ft_isdigit(data->tab[tmp][tmp2]) == 0)
				return (0);
			tmp2++;
		}
		tmp++;
	}
	return (1);
}

int	same_number(t_data *data)
{
	data->tmp = 0;
	while (data->tab[data->tmp])
	{
		data->tmp2 = data->tmp + 1;
		while (data->tab[data->tmp2])
		{
			if (ft_atoi(data->tab[data->tmp]) == ft_atoi(data->tab[data->tmp2]))
				return (0);
			data->tmp2++;
		}
		data->tmp++;
	}
	return (1);
}

int	verif_all(t_data *data)
{
	if (verif_if_consecutif_sign(data) == 0)
		return (0);
	else if (verif_sign(data) == 0)
		return (0);
	else if (same_number(data) == 0)
		return (0);
	else if (max_int(data) == 0)
		return (0);
	return (1);
}
