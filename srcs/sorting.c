/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:28:13 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:28:41 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	s_len;

	s_len = stack_size(*a);
	if (s_len-- > 3 && !is_sorted(*a))
		pb(a, b, 1);
	if (s_len-- > 3 && !is_sorted(*a))
		pb(a, b, 1);
	while (s_len-- > 3 && !is_sorted(*a))
	{
		set_node((*a), (*b));
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		reset_node((*a), (*b));
		push_b_to_a_alt(a, b);
	}
	fix_stack(a);
}

int	is_the_greater(t_stack_node *s, t_stack_node *to_test)
{
	while (s != NULL)
	{
		if (s->number > to_test->number)
			return (0);
		s = s->next;
	}
	return (1);
}

void	sort_three(t_stack_node **a)
{
	if (is_the_greater(*a, *a))
		ra(a, 1);
	else if (is_the_greater(*a, (*a)->next))
		rra(a, 1);
	if ((*a)->number > ((*a)->next)->number)
		sa(a, 1);
}

bool	is_sorted(t_stack_node *a)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->next)
		{
			if (a->number < a->next->number)
				a = a->next;
			else
				return (false);
		}
		else
			break ;
	}
	return (true);
}
