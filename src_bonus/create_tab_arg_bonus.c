/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_arg_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:20:56 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 17:12:35 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

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

int	verif(char s1, char *str)
{
	if (s1 == '\0')
	{
		if (str[0] != '\0')
			free(str);
		return (0);
	}
	return (1);
}

int	help(t_data *data, char *str)
{
	data->tab = ft_split(str, ' ');
	if (!data->tab)
		return (0);
	return (1);
}

int	create_tab_arg(t_data *data)
{
	char	*str;
	char	*temp;

	data->tmp = 1;
	str = "";
	while (data->argment[data->tmp])
	{
		if (verif(data->argment[data->tmp][0], str) == 0)
			return (0);
		temp = ft_strjoin(str, data->argment[data->tmp]);
		if (!temp)
			return (0);
		if (str[0] != '\0')
			free(str);
		str = ft_strjoin(temp, " ");
		free(temp);
		if (!str)
			return (0);
		temp = NULL;
		data->tmp++;
	}
	if (help(data, str) == 0)
		return (0);
	free(str);
	return (1);
}
