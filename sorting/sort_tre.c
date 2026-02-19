/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:09:41 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/19 16:33:21 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tre(t_list **stack)
{
	int		i;
	t_list	*curr;
	t_list	*middle;
	t_list	*last;

	i = 0;
	curr = (*stack);
	middle = (*stack)->next;
	last = (*stack)->next->next;
	if ((curr->content > middle->content)
		&& (curr->content < last->content))
		sa(stack);
	if ((curr->content > middle->content)
		&& (curr->content > last->content))
	{
		ra(stack);
		if (middle->content > last->content)
			sa(stack);
	}
	if ((curr->content < middle->content)
		&& (curr->content > last->content))
		rra(stack);
}
