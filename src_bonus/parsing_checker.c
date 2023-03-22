/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:16:13 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/04 17:32:37 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	checker_error_and_free(t_data *data, char **argv)
{
	if (create_tab_arg(data) == 0)
	{
		write (1, "KO\n", 3);
		free_splitdata(&data->tab);
		free(data);
		return (2);
	}
	else if (verif_all(data) == 0 || verif_vide(argv) == 0)
	{
		write (1, "KO\n", 3);
		free_splitdata(&data->tab);
		free(data);
		return (2);
	}
	else if (order_or_not(data) == 0)
	{
		write (1, "OK\n", 3);
		free_splitdata(&data->tab);
		free(data);
		return (2);
	}
	return (1);
}

int	verif_stack_order(t_pile **stack_a)
{
	t_pile	*tmp;
	t_pile	*next;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->next->content < tmp->content)
			return (0);
		next = tmp->next;
		tmp = next;
	}
	return (1);
}

int	verif_instru_3letters(char *str)
{
	if (ft_strcmp(str, "sa\n") == 1)
		return (1);
	if (ft_strcmp(str, "sb\n") == 1)
		return (1);
	if (ft_strcmp(str, "ss\n") == 1)
		return (1);
	if (ft_strcmp(str, "pa\n") == 1)
		return (1);
	if (ft_strcmp(str, "pb\n") == 1)
		return (1);
	if (ft_strcmp(str, "ra\n") == 1)
		return (1);
	if (ft_strcmp(str, "rb\n") == 1)
		return (1);
	if (ft_strcmp(str, "rr\n") == 1)
		return (1);
	return (0);
}

int	verif_instru_4letters(char *str)
{
	if (ft_strcmp(str, "rra\n") == 1)
		return (1);
	if (ft_strcmp(str, "rrb\n") == 1)
		return (1);
	if (ft_strcmp(str, "rrr\n") == 1)
		return (1);
	return (0);
}

int	verif_instru(char *str)
{
	if (ft_strlen(str) == 3)
	{
		if (verif_instru_3letters(str) == 0)
			return (0);
	}	
	else if (ft_strlen(str) == 4)
	{
		if (verif_instru_4letters(str) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}
