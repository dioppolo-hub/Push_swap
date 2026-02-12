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

/* void	printlist(t_list *p)
{
	while (p != NULL)
	{
		if (p->next != NULL)
			printf("[%s]->", (char *)p->content);
		else
			printf("[%s]", (char *)p->content);
		p = p->next;
	}
	printf("\n");
}*/
int	main(int argc, char **argv)
{
	long int	x;
	char		**temp;
	long int	num;
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	if (argc < 2)
	return (0);
	x = 0;
	while (++x <= argc)
		check_argument(argv[x]);
	x = 0;
	while (++x <= argc)
		add_stack(argv[x], &stack_a);
}