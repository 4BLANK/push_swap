#include "../includes/push_swap.h"

void	stack_init(char **av, t_stack_node **head)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	if (!head)
		return (free_stack(head, 1));
	while (av && av[i])
	{
		number = ft_atoi(av[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (free_stack(head, 1));
		}
		add_node(head, create_node(number, i));
		free(av[i]);
		i++;
	}
	free(av);
}

t_stack_node	*create_node(int number, int index)
{
	t_stack_node	*node;

	node = ft_calloc(sizeof(t_stack_node), 1);
	if (!node)
		return (NULL);
	node->number = number;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	add_node(t_stack_node **head, t_stack_node *node)
{
	t_stack_node	*tmp;

	if (!(*head))
	{
		(*head) = node;
	}
	else
	{
		tmp = (*head);
		while ((*head)->next)
			(*head) = (*head)->next;
		(*head)->next = node;
		(*head) = tmp;
	}
}

int	stack_size(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	fix_stack(t_stack_node **a)
{
	t_stack_node	*min;

	min = get_min(*a);
	set_a_med_pos(*a);
	while ((*a)->number != min->number)
	{
		if (min->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
