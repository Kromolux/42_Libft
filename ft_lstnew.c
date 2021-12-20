/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:03:05 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/20 10:46:52 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = (t_list *) malloc(sizeof(*new_element));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

/*
int main(void)
{
	t_list *my_list;
	t_list *my_list2;
	t_list *my_list3;
	int		i = 0;
	char	*test ={"Ich bin ein Test!"};
	char	*test2 = {"Und noch ein Test. Diesmal etwas länger."};
	int		test3[2] = {24123, 0};

	my_list = ft_lstnew((void *) "Ich bin ein Test!");
	printf("\nmy_list test  = %s\n", my_list->content);
	my_list2 = ft_lstnew((void *) test2);
	printf("\nmy_list test2 = %s\n", my_list2->content);
	my_list3 = ft_lstnew((void *) 61583);
	//while ((int) my_list->content)
	{
		printf("\nmy_list test3 = %i\n", (int) my_list3->content);
		i++;
	}
	printf("\nmy_list test  = %s\n", my_list->content);
	printf("\nmy_list test2 = %s\n", my_list2->content);
	return (0);
}
*/