/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:18:15 by dioppolo          #+#    #+#             */
/*   Updated: 2026/02/23 12:54:09 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
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
	
	nodo1 = (t_list *)malloc(sizeof(t_list *));
	nodo2 = (t_list *)malloc(sizeof(t_list *));

	nodo1->content = "ciao";
	nodo2->content = "belli";

	nodo1->next = nodo2;
	nodo2->next = NULL;

	testa = nodo1;
	
	printlist(testa);
	printf("ultimo nodo:");
	printlist(ft_lstlast(testa));
} */