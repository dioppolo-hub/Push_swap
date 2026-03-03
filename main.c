/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:55:01 by dioppolo          #+#    #+#             */
/*   Updated: 2026/03/03 16:13:00 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	print_stack(t_list *stack, int caso)
{
	if (caso == 1)
	{
		printf("Stack_A: ");
		while (stack != NULL)
		{
			if (stack->next != NULL)
				printf("%d ", (int)stack->index);
			else
				printf("%d ", (int)stack->index);
			stack = stack->next;
		}
		printf("\n");
	}
} */
	/* if (caso == 2)
	{
		printf("Stack_B: ");
		while (stack != NULL)
		{
			if (stack->next != NULL)
				printf("[%d|%d]->", (int)stack->content, (int)stack->index);
			else
				printf("[%d|%d]", (int)stack->content, (int)stack->index);
			stack = stack->next;
		}
		printf("\n");
	}
} */

/* print_stack(stack_a, 1);
	print_stack(stack_b, 2); */

int	main(int argc, char **argv)
{
	long int	x;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	x = 1;
	while (x < argc)
		add_stack(argv[x++], &stack_a);
	indice_stack(&stack_a, ft_lstsize(stack_a));
	if (ft_lstsize(stack_a) == 2 && stack_a->content > stack_a->next->content)
		sa(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_tre(&stack_a);
	else if (ft_lstsize(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) > 5)
		chunks(&stack_a, &stack_b, ft_lstsize(stack_a));
	ft_lstclear(&stack_a);
	return (0);
}
