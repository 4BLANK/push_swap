/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:28:19 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:28:42 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_push_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->above_median)
			a->push_cost = len_a - (a->index);
		if (!a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *a)
{
	t_stack_node	*tmp;
	long			t;

	tmp = a;
	t = LONG_MAX;
	if (!a)
		return ;
	while (a)
	{
		if (a->push_cost < t)
		{
			t = a->push_cost;
			tmp = a;
		}
		a = a->next;
	}
	tmp->cheapest = true;
}

t_stack_node	*get_cheapest(t_stack_node *node)
{
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	push_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest((*a));
	if (!cheapest->above_median && !cheapest->target_node->above_median)
	{
		case1(a, b, cheapest);
	}
	else if (cheapest->above_median && cheapest->target_node->above_median)
	{
		case2(a, b, cheapest);
	}
	else if (!cheapest->above_median && cheapest->target_node->above_median)
	{
		case3(a, b, cheapest);
	}
	else if (cheapest->above_median && !cheapest->target_node->above_median)
	{
		case4(a, b, cheapest);
	}
	pb(a, b, 1);
}
