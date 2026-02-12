/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:35:54 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/12 09:51:48 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**freeall(char **mat, char *cpy)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	if (cpy)
		free(cpy);
	return (NULL);
}

static int	find_next_char(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	**s_start(char *start, int c, char *cpy, char **mat)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*start)
	{
		while (*start == c)
			start++;
		if (!*start)
			break ;
		len = find_next_char(start, c);
		if (len == -1)
			len = ft_strlen(start);
		mat[i] = ft_substr(start, 0, len);
		if (!mat[i])
			return (freeall(mat, cpy));
		i++;
		start += len;
	}
	free (cpy);
	return (mat);
}

static int	countstr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	char	*cpy;
	char	*start;

	mat = (char **)ft_calloc(countstr(s, c) + 1, sizeof(char *));
	mat[countstr(s, c)] = NULL;
	if (!mat)
		return (NULL);
	cpy = ft_strdup(s);
	if (!cpy)
		return (freeall(mat, NULL));
	start = cpy;
	if (!*start)
	{
		free(cpy);
		return (mat);
	}
	return (s_start(start, c, cpy, mat));
}
