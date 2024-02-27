/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:27:59 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:28:41 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
