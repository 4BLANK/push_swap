#include "../includes/push_swap.h"

void	pa(t_stack_node **b, t_stack_node **a, bool pr)
{
	t_stack_node	*tmp;

	tmp = NULL;
	if (!(*b))
		return ;
	if (!(*a))
	{
		(*a) = (*b);
		(*b) = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		tmp = (*b)->next;
		(*b)->next = (*a);
		(*a) = (*b);
		(*b) = tmp;
	}
	if (pr)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool pr)
{
	t_stack_node	*tmp;

	tmp = NULL;
	if (!(*a))
		return ;
	if (!(*b))
	{
		(*b) = (*a);
		(*a) = (*a)->next;
		(*b)->next = NULL;
	}
	else
	{
		tmp = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = tmp;
	}
	if (pr)
		ft_printf("pb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool pr)
{
	rra(a, 0);
	rrb(b, 0);
	if (pr)
		ft_printf("rrr\n");
}
