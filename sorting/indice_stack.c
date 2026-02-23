/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indice_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:54:34 by diego             #+#    #+#             */
/*   Updated: 2026/02/23 11:40:31 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int size, int *tmp)
{
	int	swap;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tmp[j] > tmp[j + 1])
			{
				swap = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

static void	sostituzione_while(int size, int *tmp, t_list **stack, t_list *curr)
{
	int	i;

	curr = (*stack);
	while (curr)
	{
		i = 0;
		while (i < size)
		{
			if (curr->content == tmp[i])
			{
				curr->index = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

void	rev_indice_stack(t_list **stack, int *tmp)
{
	t_list	*curr;
	int		i;

	curr = (*stack);
	i = 0;
	while (curr)
	{
		curr->content = tmp[i++];
		curr = curr->next;
	}
}

int	*indice_stack(t_list **stack, int size)
{
	int		*tmp;
	int		i;
	t_list	*curr;

	tmp = ft_calloc(sizeof(int), size);
	if (!tmp)
		return (0);
	curr = (*stack);
	i = 0;
	while (curr)
	{
		tmp[i++] = curr->content;
		curr = curr->next;
	}
	bubble_sort(size, tmp);
	sostituzione_while(size, tmp, stack, curr);
	return (tmp);
}
