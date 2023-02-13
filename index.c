/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:50:42 by rnait-el          #+#    #+#             */
/*   Updated: 2023/02/13 05:59:24 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*h;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	h = *stack;
	if (h)
	{
		while (h)
		{
			if ((h->index == -1) && (!has_min || h->content < min->content))
			{
				min = h;
				has_min = 1;
			}
			h = h->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
