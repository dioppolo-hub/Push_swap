/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:36:43 by diego             #+#    #+#             */
/*   Updated: 2026/03/04 18:05:32 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_line(void)
{
	char	*line;
	char	buffer;
	int		i;
	int		r;

	line = malloc(4);
	if (!line)
		return (NULL);
	i = 0;
	while ((r = read(0, &buffer, 1)) > 0)
	{
		if (buffer == '\n')
			break;
		line[i++] = buffer;
	}
	if (r <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

int execute_instruction(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "sa"))
		sa(a);
	else if (!ft_strcmp(line, "sb"))
		sb(b);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra"))
		ra(a);
	else if (!ft_strcmp(line, "rb"))
		rb(b);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra"))
		rra(a);
	else if (!ft_strcmp(line, "rrb"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	int		x;
	char    *line;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	x = 1;
	while (x < argc)
		add_stack(argv[x++], &a);
	while (1)
	{
		line = read_line();
		if (!line)
			break;
		if (!execute_instruction(line, &a, &b))
		{
			write(2, "Error\n", 6);
			free(line);
			free_stacks(&a, &b);
			exit(1);
		}
		free(line);
	}
	if (is_already_sort(&a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&a, &b);
	return (0);
}
