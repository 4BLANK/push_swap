/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:28:21 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:28:42 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_b_target(t_stack_node *a, t_stack_node *b, int *t)
{
	while (a)
	{
		if (a->number > b->number && a->number < *t)
			*t = a->number;
		a = a->next;
	}
}

t_stack_node	*get_t_node(t_stack_node *a, int t)
{
	t_stack_node	*node;

	node = NULL;
	while (a)
	{
		if (a->number == t)
			node = a;
		a = a->next;
	}
	return (node);
}

void	rotate_to_b_target(t_stack_node **a, int t)
{
	t_stack_node	*node;

	node = get_t_node(*a, t);
	while ((*a)->number != t)
	{
		if (!(node)->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	int	t;

	while (*b)
	{
		t = INT_MAX;
		get_b_target(*a, *b, &t);
		set_a_med_pos(*a);
		if (t == INT_MAX)
			t = get_min(*a)->number;
		rotate_to_b_target(a, t);
		pa(b, a, 1);
	}
}
