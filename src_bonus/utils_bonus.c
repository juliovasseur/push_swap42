/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:14:40 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 17:15:35 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (0);
		i++;
	}
	return (1);
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
