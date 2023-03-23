/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:15:52 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/23 13:58:34 by jvasseur         ###   ########.fr       */
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
			write (2, "KO\n", 3);
			return (0);
		}
		exec_instru(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_pile	*stack_a;
	t_pile	*stack_b;

	if (argc < 2)
		return (2);
	data = malloc(sizeof(t_data));
	if (!data)
		return (2);
	data->argc = argc;
	data->argment = argv;
	if (checker_error_and_free(data, argv) == 2)
		return (0);
	stack_b = NULL;
	tokenize(data, &stack_a);
	if (get_instru(&stack_a, &stack_b, data) == 0)
		return (2);
	else if (final_verif_and_free(stack_a, stack_b, data) == 0)
		return (2);
	free_splitdata(&data->tab);
	free(data);
	freelst(&stack_a);
	return (1);
}
