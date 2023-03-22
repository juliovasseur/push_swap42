/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:28:29 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/02 19:00:43 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_splitdata(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free((*str));
}

int	create_tab_arg(t_data *data)
{
	char	*str;
	char	*temp;

	data->tmp = 1;
	str = "";
	data->tmp = 1;
	while (data->argment[data->tmp])
	{
		if (data->argment[data->tmp][0] == '\0' )
		{
			if (str[0] != '\0')
				free(str);
			return (0);
		}
		temp = ft_strjoin(str, data->argment[data->tmp]);
		if (str[0] != '\0')
			free(str);
		str = ft_strjoin(temp, " ");
		free(temp);
		data->tmp++;
	}
	data->tab = ft_split(str, ' ');
	free(str);
	return (1);
}
