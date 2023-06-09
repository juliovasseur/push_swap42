/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:15:52 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/25 18:47:54 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	verif_if_stack_empty(t_pile *stack)
{
	if (stack != NULL)
		return (0);
	return (1);
}

int	final_verif_and_free(t_pile *stack_a, t_pile *stack_b, t_data *data)
{
	if (verif_if_stack_empty(stack_b) == 0)
	{
		write (1, "KO\n", 3);
		free_splitdata(&data->tab);
		free(data);
		freelst(&stack_b);
		freelst(&stack_a);
		return (0);
	}
	if (verif_stack_order(&stack_a) == 0)
	{
		write (1, "KO\n", 3);
		free_splitdata(&data->tab);
		free(data);
		freelst(&stack_a);
		return (0);
	}
	else
		write (1, "OK\n", 3);
	return (1);
}

int	get_instru(t_pile **stack_a, t_pile **stack_b, t_data *data)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (verif_instru(str) == 0)
		{
			free(str);
			free_splitdata(&data->tab);
			free(data);
			freelst(stack_a);
			write (2, "Error\n", 6);
			return (0);
		}
		exec_instru(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
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

int	main(int argc, char **argv)
{
	t_data	*data;
	t_pile	*stack_a;
	t_pile	*stack_b;

	if (argc < 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->argc = argc;
	data->argment = argv;
	if (checker_error_and_free(data, argv) == 2)
		return (0);
	stack_b = NULL;
	tokenize(data, &stack_a);
	if (get_instru(&stack_a, &stack_b, data) == 0)
		return (0);
	else if (final_verif_and_free(stack_a, stack_b, data) == 0)
		return (0);
	free_splitdata(&data->tab);
	free(data);
	freelst(&stack_a);
	return (1);
}
