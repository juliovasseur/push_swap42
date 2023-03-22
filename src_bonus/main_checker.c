/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:15:52 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/04 17:30:42 by jvasseur         ###   ########.fr       */
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


int	final_verif_and_free(t_pile *stack_a, t_data *data)
{
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

int	get_instru(t_pile **stack_a, t_pile **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (verif_instru(str) == 0)
		{
			free(str);
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
	data->argc = argc;
	data->argment = argv;
	if (checker_error_and_free(data, argv) == 2)
		return (2);
	stack_b = NULL;
	tokenize(data, &stack_a);
	if (get_instru(&stack_a, &stack_b) == 0)
	{
		free_splitdata(&data->tab);
		free(data);
		freelst(&stack_a);
		return (2);
	}
	else if (final_verif_and_free(stack_a, data) == 0)
		return (2);
	free_splitdata(&data->tab);
	free(data);
	freelst(&stack_a);
	return (1);
}
