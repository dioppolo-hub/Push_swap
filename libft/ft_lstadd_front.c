/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:40:52 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/16 14:32:40 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
}
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
}
int		main()
{
	t_list *testa;
	t_list *nodo1 = NULL;
	t_list *nodo2 = NULL;
	t_list *new = NULL;
	
	nodo1 = (t_list *)malloc(sizeof(t_list *));
	nodo2 = (t_list *)malloc(sizeof(t_list *));
	new = (t_list *)malloc(sizeof(t_list *));

	nodo1->content = "a";
	nodo2->content = "tutti";
	new->content = "ciao";

	nodo1->next = nodo2;
	nodo2->next = NULL;

	testa = nodo1;
	
	printf("prima:\n");
	printlist(testa);
	ft_lstadd_front(&testa, new);
	printf("dopo:\n");
	printlist(testa);
} */