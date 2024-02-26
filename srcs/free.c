#include "../includes/push_swap.h"

void	free_stack(t_stack_node **head, int status)
{
	t_stack_node	*next;

	if (!head || !(*head))
		exit(1);
	while (*head)
	{
		next = (*head)->next;
		(*head)->number = 0;
		free((*head));
		(*head) = next;
	}
	head = NULL;
	exit(status);
}
