/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:28:32 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:28:42 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case1_alt(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while ((*b)->number != cheapest->number
		&& (*a)->number != cheapest->target_node->number)
		rr(a, b, 1);
	while ((*b)->number != cheapest->number)
		rb(b, 1);
	while ((*a)->number != cheapest->target_node->number)
		ra(a, 1);
}

void	case2_alt(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while ((*b)->number != cheapest->number
		&& (*a)->number != cheapest->target_node->number)
		rrr(a, b, 1);
	while ((*b)->number != cheapest->number)
		rrb(b, 1);
	while ((*a)->number != cheapest->target_node->number)
		rra(a, 1);
}

void	case3_alt(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while ((*b)->number != cheapest->number)
		rb(b, 1);
	while ((*a)->number != cheapest->target_node->number)
		rra(a, 1);
}

void	case4_alt(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while ((*b)->number != cheapest->number)
		rrb(b, 1);
	while ((*a)->number != cheapest->target_node->number)
		ra(a, 1);
}

void	set_a_med_pos(t_stack_node *a)
{
	int	i;
	int	med;

	med = stack_size(a) / 2;
	i = 0;
	while (i <= med)
	{
		a->above_median = true;
		a = a->next;
		i++;
	}
	while (i < stack_size(a))
	{
		a->above_median = false;
		a = a->next;
		i++;
	}
}
