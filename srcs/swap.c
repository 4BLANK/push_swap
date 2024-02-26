#include "../includes/push_swap.h"

void	sa(t_stack_node **a, bool pr)
{
	t_stack_node	*tmp;

	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	(*a) = tmp;
	if (pr)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool pr)
{
	t_stack_node	*tmp;

	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = (*b);
	(*b) = tmp;
	if (pr)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool pr)
{
	sa(a, 0);
	sb(b, 0);
	if (pr)
		ft_printf("ss\n");
}
