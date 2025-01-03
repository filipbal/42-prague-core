/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:50:02 by fbalakov          #+#    #+#             */
/*   Updated: 2024/12/10 18:06:02 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
	Adds new node to back of stack
	If stack empty: node becomes both head and tail
	If stack has nodes: connects new node after current tail
	Increments stack size
*/
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

/* 
	Linear search O(n) that traverses stack once
	Returns 1 if stack is empty, contains 1 node or sorted in ASC order
	Returns 0 if any adjacent pair is out of order
*/
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
