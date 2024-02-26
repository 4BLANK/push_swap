#include "../includes/push_swap.h"

void	reset_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	long			closest;
	t_stack_node	*tmp_a;

	while (b)
	{
		tmp_a = a;
		closest = LONG_MAX;
		while (tmp_a)
		{
			if (tmp_a->number > b->number && tmp_a->number < closest)
			{
				closest = tmp_a->number;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (closest == LONG_MAX)
			b->target_node = get_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	reset_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp;

	tmp = b;
	while (tmp)
	{
		tmp->cheapest = false;
		tmp = tmp->next;
	}
	set_index(a);
	set_index(b);
	reset_target(a, b);
	set_push_cost(b, a);
	set_cheapest(b);
}

void	push_b_to_a_alt(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest((*b));
	if (!cheapest->above_median && !cheapest->target_node->above_median)
	{
		case1_alt(a, b, cheapest);
	}
	else if (cheapest->above_median && cheapest->target_node->above_median)
	{
		case2_alt(a, b, cheapest);
	}
	else if (!cheapest->above_median && cheapest->target_node->above_median)
	{
		case3_alt(a, b, cheapest);
	}
	else if (cheapest->above_median && !cheapest->target_node->above_median)
	{
		case4_alt(a, b, cheapest);
	}
	pa(b, a, 1);
}
