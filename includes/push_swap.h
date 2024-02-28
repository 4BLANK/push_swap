/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:27:01 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:27:03 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					number;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}						t_stack_node;

void					add_node(t_stack_node **head, t_stack_node *node);
int						stack_size(t_stack_node *stack);
bool					is_sorted(t_stack_node *a);
void					stack_init(char **av, t_stack_node **head);
t_stack_node			*create_node(int number, int index);
void					sa(t_stack_node **a, bool pr);
void					sb(t_stack_node **b, bool pr);
void					ss(t_stack_node **a, t_stack_node **b, bool pr);
void					pa(t_stack_node **b, t_stack_node **a, bool pr);
void					pb(t_stack_node **a, t_stack_node **b, bool pr);
void					ra(t_stack_node **a, bool pr);
void					rb(t_stack_node **b, bool pr);
void					rr(t_stack_node **a, t_stack_node **b, bool pr);
void					rra(t_stack_node **a, bool pr);
void					rrb(t_stack_node **b, bool pr);
void					rrr(t_stack_node **a, t_stack_node **b, bool pr);
void					print_stack(t_stack_node *node);
void					sort_three(t_stack_node **a);
void					set_node(t_stack_node *a, t_stack_node *b);
void					sort_stack(t_stack_node **a, t_stack_node **b);
void					free_stack(t_stack_node **head, int status);
bool					check_dup(t_stack_node *stack);
void					push_a_to_b(t_stack_node **a, t_stack_node **b);
void					case1(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					case2(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					case3(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					case4(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
t_stack_node			*get_min(t_stack_node *node);
t_stack_node			*get_max(t_stack_node *node);
void					set_index(t_stack_node *node);
void					set_target(t_stack_node *a, t_stack_node *b);
void					set_push_cost(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *a);
t_stack_node			*get_cheapest(t_stack_node *node);
void					get_b_target(t_stack_node *a, t_stack_node *b, int *t);
void					set_a_med_pos(t_stack_node *a);
t_stack_node			*get_t_node(t_stack_node *a, int t);
void					rotate_to_b_target(t_stack_node **a, int t);
void					push_b_to_a(t_stack_node **a, t_stack_node **b);
void					fix_stack(t_stack_node **a);
bool					check_wrong_input(char *args);
void					push_b_to_a_alt(t_stack_node **a, t_stack_node **b);
void					reset_node(t_stack_node *a, t_stack_node *b);
void					case1_alt(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					case2_alt(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					case3_alt(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					case4_alt(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest);
void					set_a_med_pos(t_stack_node *a);
void					handle_different_args(char **av);
void					free_av(char **av);

#endif
