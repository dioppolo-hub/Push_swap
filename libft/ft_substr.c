/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:48:23 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/19 09:17:19 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*s_str(char const *str, unsigned int start,
					size_t len, char *substr)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!str || !substr)
		return (NULL);
	while (str[i] && i < start)
		i++;
	while (str[i] && j < len)
	{
		substr[j] = str[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	lenstr;
	char	*substr;

	if (!str)
		return (NULL);
	lenstr = ft_strlen(str);
	if (start > lenstr)
		return (ft_strdup(""));
	if (len > lenstr - start)
		len = lenstr - start;
	if (len == 0)
		return (ft_strdup(""));
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	return (s_str(str, start, len, substr));
}
