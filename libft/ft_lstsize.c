/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioppolo <dioppolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:07:37 by dioppolo          #+#    #+#             */
/*   Updated: 2025/12/15 16:09:46 by dioppolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*corrente;

	count = 0;
	corrente = lst;
	while (corrente != NULL)
	{
		count++;
		corrente = corrente->next;
	}
	return (count);
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
	printf("dimensione lista:%d\n", ft_lstsize(testa));
} */