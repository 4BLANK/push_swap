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
