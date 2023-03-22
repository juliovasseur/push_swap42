/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:30:33 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/04 19:08:35 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H


# include "../Libft/libft.h"
# include<string.h>
# include<stdlib.h>
# include<unistd.h>
# include<stddef.h>
# include<limits.h>
# include<fcntl.h>

typedef struct s_pile
{
	struct s_pile	*next;
	int				content;
	int				size;
}					t_pile;

typedef struct s_data {
	int		tmp;
	int		tmp2;
	int		tmp3;
	char	**argment;
	char	**tab;
	int		argc;
	int		cpt;
	int		pivot;
	int		equalpivot;
	int		pivotmp;
}				t_data;

void	lstadd_back(t_pile **lst, t_pile *new);
t_pile	*lstnew(int content);
int		verif_all(t_data *data);
int		create_tab_arg(t_data *data);
void	lstadd_front(t_pile **pile, t_pile *pile2);
void	printfpile(t_pile **a);
void	tokenize(t_data *data, t_pile **stacka);
void	sort_in_tab(t_pile **stacka, t_pile **stackb, t_data *data, int len);
void	create_stacka(t_pile **stacka, int *stacktoken, int len);
void	push_beginstack(t_pile **stacka, t_pile **stackb, int pos, int len);
void	init(int content, t_pile **b);
int		ft_stacksize(t_pile **stack);
int		nbarg(char **tab);
int		order_or_not(t_data *data);
void	sort_in_two(t_pile **stacka);
void	sort_in_tree(t_pile **stacka);
void	sort_in_four(t_pile **stacka, t_pile **stackb);
void	sort_in_five(t_pile **stacka, t_pile **stackb);
void	print_instru(int i);
void	swap_a(t_pile **stacka, int i);
void	swap_b(t_pile **stackb, int i);
void	swap_ss(t_pile **stacka, t_pile **stackb, int i);
void	push(t_pile **begin, t_pile **stackpush, int j);
void	rotate(t_pile **stack, int i);
void	rotate_rr(t_pile **stack, t_pile **stackb, int i);
void	rra(t_pile **stack, int i);
void	rrb(t_pile **stack, int i);
void	rrr(t_pile **stack, t_pile **stackb, int i);
int		pos_content(t_pile **a, int i);
int		pos_contentwo(t_pile **a, int i, int j);
int		pos_pivot(t_pile **a, int pivot, int equalpivot);
void	sort_in_reverse_tab(t_pile **a, t_pile **b, t_data *data, int len);
int		verif_vide(char **argv);
void	free_splitdata(char ***str);
void	freelst(t_pile **lst);
int		order_or_not(t_data *data);
int		verif_vide(char **argv);
int		max_int(t_data *data);
void	norm_sorttab(t_pile **stacka, t_pile **stackb, t_data *data, int len);
void	exec_instru(t_pile **stack_a, t_pile **stack_b, char *str);
int		checker_error_and_free(t_data *data, char **argv);
int		verif_stack_order(t_pile **stack_a);
int		verif_instru_3letters(char *str);
int		verif_instru_4letters(char *str);
int		verif_instru(char *str);
int		ft_strcmp(char *s1, char *s2);
int		check_error_and_free(t_data *data, char **argv);
void	ft_algo(t_pile **stacka, t_pile **stackb, t_data *data);

#endif
