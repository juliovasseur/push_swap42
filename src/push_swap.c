/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:42:50 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/04 19:08:51 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (check_error_and_free(data, argv) == 2)
		return (0);
	stack_b = NULL;
	tokenize(data, &stack_a);
	ft_algo(&stack_a, &stack_b, data);
	free_splitdata(&data->tab);
	free(data);
	freelst(&stack_a);
}
