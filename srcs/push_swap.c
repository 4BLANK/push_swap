/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:28:08 by amasdouq          #+#    #+#             */
/*   Updated: 2024/02/27 22:28:41 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	process_args(int ac, char **av, t_stack_node **a)
{
	char	*args;
	int		i;

	i = 1;
	args = NULL;
	while (i < ac)
	{
		args = ft_strjoin(args, " ");
		args = ft_strjoin(args, av[i++]);
	}
	if (check_wrong_input(args))
	{
		write(2, "Error\n", 6);
		free(args);
		exit(1);
	}
	av = ft_split(args, ' ');
	free(args);
	stack_init(av, a);
	if (!a || check_dup(*a))
	{
		write(2, "Error\n", 6);
		free_stack(a, 1);
	}
}

int	main(int ac, char *av[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || !av[1][0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	process_args(ac, av, &a);
	if (!is_sorted(a))
	{
		if (stack_size(a) <= 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a, 0);
}
