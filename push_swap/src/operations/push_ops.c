/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:21:04 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 15:32:47 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_to_push;

	if (!stack_b || !stack_b->h)
		return ;
	node_to_push = stack_b->h;
	stack_b->h = stack_b->h->next;
	if (stack_b->h)
		stack_b->h->prev = NULL;
	else
		stack_b->tail = NULL;
	stack_b->size--;
	node_to_push->next = stack_a->h;
	if (stack_a->h)
		stack_a->h->prev = node_to_push;
	else
		stack_a->tail = node_to_push;
	stack_a->h = node_to_push;
	node_to_push->prev = NULL;
	stack_a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_to_push;

	if (!stack_a || !stack_a->h)
		return ;
	node_to_push = stack_a->h;
	stack_a->h = stack_a->h->next;
	if (stack_a->h)
		stack_a->h->prev = NULL;
	else
		stack_a->tail = NULL;
	stack_a->size--;
	node_to_push->next = stack_b->h;
	if (stack_b->h)
		stack_b->h->prev = node_to_push;
	else
		stack_b->tail = node_to_push;
	stack_b->h = node_to_push;
	node_to_push->prev = NULL;
	stack_b->size++;
	write(1, "pb\n", 3);
}
