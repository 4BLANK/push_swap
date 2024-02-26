/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:34:07 by amasdouq          #+#    #+#             */
/*   Updated: 2023/11/17 23:42:34 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	revstr(char *res, int len)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	len--;
	while (i < len)
	{
		c = res[i];
		res[i] = res[len];
		res[len] = c;
		i++;
		len--;
	}
}

static void	fill_str(char *res, long int n, int index, int len)
{
	while (index < len)
	{
		res[index] = (n % 10) + '0';
		n /= 10;
		index++;
	}
	revstr(res, len);
}

char	*ft_itoa(int n)
{
	char		*res;
	long int	num;
	int			len;
	int			i;
	int			s;

	res = 0;
	num = (long int)n;
	i = 0;
	s = 0;
	len = count_digits(num);
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		num *= -1;
		s = 1;
	}
	res = (char *)ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	fill_str(res, num, i, len);
	if (s)
		res[0] = '-';
	return (res);
}
