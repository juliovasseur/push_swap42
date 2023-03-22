/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:30:18 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/04 17:31:56 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	exec_instru_3_letters(t_pile **stack_a, t_pile **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 1)
		swap_a(stack_a, 11);
	else if (ft_strcmp(str, "sb\n") == 1)
		swap_b(stack_b, 11);
	else if (ft_strcmp(str, "ss\n") == 1)
		swap_ss(stack_a, stack_a, 11);
	else if (ft_strcmp(str, "pa\n") == 1)
		push(stack_a, stack_b, 11);
	else if (ft_strcmp(str, "pb\n") == 1)
		push(stack_a, stack_a, 11);
	else if (ft_strcmp(str, "ra\n") == 1)
		rotate(stack_a, 11);
	else if (ft_strcmp(str, "rb\n") == 1)
		rotate(stack_b, 11);
	else if (ft_strcmp(str, "rr\n") == 1)
		rotate_rr(stack_a, stack_b, 11);
}

void	exec_instru_4_letters(t_pile **stack_a, t_pile **stack_b, char *str)
{
	if (ft_strcmp(str, "rra\n") == 1)
		rra(stack_a, 11);
	else if (ft_strcmp(str, "rrb\n") == 1)
		rrb(stack_b, 11);
	else if (ft_strcmp(str, "rrr\n") == 1)
		rrr(stack_a, stack_a, 11);
}

void	exec_instru(t_pile **stack_a, t_pile **stack_b, char *str)
{
	if (ft_strlen(str) == 3)
		exec_instru_3_letters(stack_a, stack_b, str);
	else if (ft_strlen(str) == 4)
		exec_instru_4_letters(stack_a, stack_b, str);
}
