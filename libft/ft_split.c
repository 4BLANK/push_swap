/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:34:08 by amasdouq          #+#    #+#             */
/*   Updated: 2023/11/26 00:28:14 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, int i)
{
	while (i + 1)
		free(str[i--]);
	free(str);
	return (NULL);
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*allocate_to_word(const char *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	word = NULL;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)ft_calloc(i + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	chi_haja(const char **s, char c, size_t *i)
{
	(*i)++;
	while (**s && **s != c)
		(*s)++;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	words;

	i = 0;
	if (!s)
		return (NULL);
	words = word_count((char *)s, c) + 1;
	res = (char **)ft_calloc(words, sizeof(char *));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			res[i] = allocate_to_word(s, c);
			if (!res[i])
				return (ft_free(res, i));
			chi_haja(&s, c, &i);
		}
	}
	res[i] = NULL;
	return (res);
}
