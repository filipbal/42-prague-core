/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:50:02 by fbalakov          #+#    #+#             */
/*   Updated: 2024/11/18 12:15:53 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	stack_add_front
    stack_add_back
    stack_pop_front
    get_min_value
    get_max_value
*/

#include "../../includes/push_swap.h"

void	stack_add_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->prev = stack->tail;
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
	stack->size++;
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
