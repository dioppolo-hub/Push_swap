/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:55:01 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/17 15:52:59 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_list *stack, int caso)
{
	if(caso == 1)
	{
		printf("Stack_A: ");
		while (stack != NULL)
		{
			if (stack->next != NULL)
				printf("[%d]->", (int)stack->content);
			else
				printf("[%d]", (int)stack->content);
			stack = stack->next;
		}
		printf("\n");
	}
	if(caso == 2)
	{
		printf("Stack_B: ");
		while (stack != NULL)
		{
			if (stack->next != NULL)
				printf("[%d]->", (int)stack->content);
			else
				printf("[%d]", (int)stack->content);
			stack = stack->next;
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	long int	x;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	x = 1;
	while (x < argc)
	{
		add_stack(argv[x], &stack_a);
		x++;
	}
	print_stack(stack_a, 1);
	print_stack(stack_b, 2);
	rra(&stack_a);
	print_stack(stack_a, 1);
	print_stack(stack_b, 2);
	return (0);
}
