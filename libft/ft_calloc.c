/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:16:25 by amasdouq          #+#    #+#             */
/*   Updated: 2023/11/27 10:41:21 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*p;
	size_t	total;

	p = NULL;
	total = nelem * elsize;
	if (!total)
		return (malloc(0));
	if (nelem && ((total / nelem) != elsize))
		return (NULL);
	p = (void *)malloc(total);
	if (!p)
		return (NULL);
	ft_bzero(p, total);
	return ((void *)p);
}
