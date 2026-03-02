/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_generico.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 21:57:03 by  diego            #+#    #+#             */
/*   Updated: 2026/03/02 10:36:02 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static void	push_middle(t_list **stack_a, t_list **stack_b, int ra)
{
	int		moves;
	int		min_move;
	int		pos;
	t_list	*curr;
	int		best_ra;

	ra = 0;
	min_move = -1;
	curr = (*stack_a);
	while (curr != NULL)
	{
		pos = find_pos(curr->index, stack_b);
		moves = calc_moves(pos, ra, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		if (moves < min_move || min_move == -1)
		{
			best_ra = ra;
			min_move = moves;
		}
		curr = curr->next;
		ra++;
	}
	push_index(best_ra, stack_a, stack_b);
}

static void	push_back(t_list **stack_a, t_list **stack_b, int rb)
{
	int		pos;
	int		moves;
	int		best_rb;
	int		min_move;
	t_list	*curr;

	min_move = -1;
	curr = *stack_b;
	while (curr)
	{
		pos = find_pos_in_a(curr->index, stack_a);
		moves = calc_moves(rb, pos, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		if (moves < min_move || min_move == -1)
		{
			min_move = moves;
			best_rb = rb;
		}
		curr = curr->next;
		rb++;
	}
	execute_rotations_back(best_rb, stack_a, stack_b);
}

static void	sort_to_b(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	while (ft_lstsize(*stack_a) > 3)
		push_middle(stack_a, stack_b, 0);
	sort_tre(stack_a);
}

void	sort_generico(t_list **stack_a, t_list **stack_b)
{
	sort_to_b(stack_a, stack_b);
	while (*stack_b)
		push_back(stack_a, stack_b, 0);
	while ((*stack_a)->index != 0)
		ra(stack_a);
}
