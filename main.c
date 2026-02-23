/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:55:01 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/23 14:27:59 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack, int caso)
{
	if (caso == 1)
	{
		printf("Stack_A: ");
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
	if (caso == 2)
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
}

void	print_tmparr(int *arr, int size)
{
	int	i;

	printf("Tmp_Array: ");
	i = 0;
	while (i < size)
	{
		if (i < size - 1)
			printf("[%d]->", arr[i]);
		else
			printf("[%d]", arr[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	long int	x;
	int			size;
	int			*tmp;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	x = 1;
	while (x < argc)
		add_stack(argv[x++], &stack_a);
	size = ft_lstsize(stack_a);
	tmp = indice_stack(&stack_a, size);
	print_stack(stack_a, 1);
	print_stack(stack_b, 2);
	if (size == 2 && stack_a->content > stack_a->next->content)
		sa(&stack_a);
	if (size == 3)
		sort_tre(&stack_a);
	if (size == 4)
		sort_four(&stack_a, &stack_b);
	if (size == 5)
		sort_five(&stack_a, &stack_b);
	if (size > 5)
		sort_generico(&stack_a, &stack_b, size);
	print_stack(stack_a, 1);
	print_stack(stack_b, 2);
	return (0);
}
