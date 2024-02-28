/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:27:57 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:28:41 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	check_dup(t_stack_node *stack)
{
	t_stack_node	*temp_node;

	while (stack)
	{
		temp_node = stack->next;
		while (temp_node)
		{
			if (temp_node->number == stack->number)
				return (true);
			temp_node = temp_node->next;
		}
		stack = stack->next;
	}
	return (false);
}

bool	check_empty(char *args)
{
	int	i;
	int	len;

	i = 0;
	if (!args)
		return (true);
	len = ft_strlen(args);
	while (args[i] == ' ')
		i++;
	if (i == len)
		return (true);
	return (false);
}

bool	check_misc(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i] != '+' && args[i] != '-' && args[i] != ' ' && (args[i] < '0'
				|| args[i] > '9'))
			return (true);
		i++;
	}
	return (false);
}

bool	check_wrong_input(char *args)
{
	int	i;

	i = 0;
	if (check_misc(args) || check_empty(args))
		return (true);
	i = 0;
	while (args[i])
	{
		if (args[i] == '-' || args[i] == '+')
		{
			if (!ft_isdigit(args[i + 1]))
				return (true);
			if (i != 0 && args[i - 1] != ' ')
				return (true);
		}
		i++;
	}
	return (false);
}

void	handle_different_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (check_empty(av[i++]))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
}
