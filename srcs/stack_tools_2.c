#include "../includes/push_swap.h"

void	set_node(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_push_cost(a, b);
	set_cheapest(a);
}

t_stack_node	*get_max(t_stack_node *node)
{
	t_stack_node	*largest;

	largest = node;
	while (node)
	{
		if (node->number > largest->number)
			largest = node;
		node = node->next;
	}
	return (largest);
}

t_stack_node	*get_min(t_stack_node *node)
{
	t_stack_node	*smallest;

	smallest = node;
	while (node)
	{
		if (node->number < smallest->number)
			smallest = node;
		node = node->next;
	}
	return (smallest);
}

void	set_index(t_stack_node *node)
{
	int	median;
	int	i;

	median = stack_size(node) / 2;
	i = 0;
	while (node)
	{
		node->index = i;
		if (node->index <= median)
			node->above_median = false;
		else
			node->above_median = true;
		node = node->next;
		i++;
	}
}

void	set_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	long			closest;
	t_stack_node	*tmp_b;

	while (a)
	{
		tmp_b = b;
		closest = LONG_MIN;
		while (tmp_b)
		{
			if (tmp_b->number < a->number && tmp_b->number > closest)
			{
				closest = tmp_b->number;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (closest == LONG_MIN)
			a->target_node = get_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}
