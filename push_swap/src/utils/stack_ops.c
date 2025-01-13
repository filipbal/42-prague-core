/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:50:02 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 15:33:35 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Adds a node to the end of stack
** Error exits if stack or node is NULL
*/

void	stack_add_back(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
	{
		if (new_node)
			free(new_node);
		error_exit();
	}
	if (!stack->h)
	{
		stack->h = new_node;
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

/*
** Checks if stack values are in ascending order
** Returns: 1 if sorted, 0 if not sorted
** Empty stack is considered sorted
*/
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->h)
		return (1);
	current = stack->h;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
