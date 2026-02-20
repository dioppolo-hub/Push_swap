/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:09:41 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/20 19:26:42 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tre(t_list **stack)
{
	t_list	*curr;
	t_list	*middle;
	t_list	*last;

	curr = (*stack);
	middle = (*stack)->next;
	last = (*stack)->next->next;
	if ((curr->content > middle->content) && (curr->content < last->content))
		sa(stack);
	if ((curr->content > middle->content) && (curr->content > last->content))
	{
		ra(stack);
		if (middle->content > last->content)
			sa(stack);
	}
	if ((curr->content < middle->content)
		&& (curr->content > last->content))
		rra(stack);	
	if ((curr->content < middle->content) && (middle->content > last->content)
		&& (curr->content < last->content))
	{
		rra(stack);
		sa(stack);
	}
}
