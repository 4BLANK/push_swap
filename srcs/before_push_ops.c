/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_push_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:27:54 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:28:41 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case1(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while ((*a)->number != cheapest->number
		&& (*b)->number != cheapest->target_node->number)
		rr(a, b, 1);
	while ((*a)->number != cheapest->number)
		ra(a, 1);
	while ((*b)->number != cheapest->target_node->number)
		rb(b, 1);
}

void	case2(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while ((*a)->number != cheapest->number
		&& (*b)->number != cheapest->target_node->number)
		rrr(a, b, 1);
	while ((*a)->number != cheapest->number)
		rra(a, 1);
	while ((*b)->number != cheapest->target_node->number)
		rrb(b, 1);
}

void	case3(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while ((*a)->number != cheapest->number)
		ra(a, 1);
	while ((*b)->number != cheapest->target_node->number)
		rrb(b, 1);
}

void	case4(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while ((*a)->number != cheapest->number)
		rra(a, 1);
	while ((*b)->number != cheapest->target_node->number)
		rb(b, 1);
}
