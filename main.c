/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:55:01 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/12 12:35:05 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_list *stack)
{
	printf("Stack_A: ");
	while (stack != NULL)
	{
		if (stack->next != NULL)
			printf("[%d]->", *(int *)stack->content);
		else
			printf("[%d]", *(int *)stack->content);
		stack = stack->next;
	}
	printf("\n");
}
int	main(int argc, char **argv)
{
	long int	x;
	t_list	*stack_a;
//	t_list	*stack_b;

	stack_a = NULL;
//	stack_b = NULL;
	if (argc < 2)
		return (0);
	x = 1;
	while (x < argc)
	{
		add_stack(argv[x], &stack_a);
		x++;
	}
	x = 1;
	while (x < argc)
	{
		check_argument(argv[x]);
		x++;
	}
	print_stack(stack_a);
	return (0);
}
