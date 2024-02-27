/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:28:11 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:28:41 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack_node **a, bool pr)
{
	t_stack_node	*first;
	t_stack_node	*new_first;
	t_stack_node	*last;

	first = (*a);
	new_first = (*a)->next;
	last = NULL;
	while ((*a)->next)
		(*a) = (*a)->next;
	last = (*a);
	last->next = first;
	first->next = NULL;
	(*a) = new_first;
	if (pr)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool pr)
{
	t_stack_node	*first;
	t_stack_node	*new_first;
	t_stack_node	*last;

	first = (*b);
	new_first = (*b)->next;
	last = NULL;
	while ((*b)->next)
		(*b) = (*b)->next;
	last = (*b);
	last->next = first;
	first->next = NULL;
	(*b) = new_first;
	if (pr)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool pr)
{
	ra(a, 0);
	rb(b, 0);
	if (pr)
		ft_printf("rr\n");
}

void	rra(t_stack_node **a, bool pr)
{
	t_stack_node	*first;
	t_stack_node	*last;
	t_stack_node	*new_last;

	first = (*a);
	last = NULL;
	new_last = NULL;
	while ((*a)->next->next)
		(*a) = (*a)->next;
	new_last = (*a);
	(*a) = (*a)->next;
	last = (*a);
	last->next = first;
	new_last->next = NULL;
	(*a) = last;
	if (pr)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool pr)
{
	t_stack_node	*first;
	t_stack_node	*last;
	t_stack_node	*new_last;

	first = (*b);
	last = NULL;
	new_last = NULL;
	while ((*b)->next->next)
		(*b) = (*b)->next;
	new_last = (*b);
	(*b) = (*b)->next;
	last = (*b);
	last->next = first;
	new_last->next = NULL;
	(*b) = last;
	if (pr)
		ft_printf("rrb\n");
}
