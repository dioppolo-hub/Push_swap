/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:35:32 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/19 09:17:59 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **receiver, t_list **giver)
{
	t_list	*temp;
	t_list	*a;

	if (!(*giver))
		return ;
	temp = (*giver);
	a = (*giver)->next;
	ft_lstadd_front(receiver, temp);
	(*giver) = a;
	(*receiver) = temp;
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write (1, "pa\n", 3);
	return (1);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write (1, "pb\n", 3);
	return (1);
}
