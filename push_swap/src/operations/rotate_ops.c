/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:21:13 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 15:33:04 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*first;

	if (!stack_a || !stack_a->h || !stack_a->h->next)
		return ;
	first = stack_a->h;
	stack_a->h = first->next;
	stack_a->h->prev = NULL;
	stack_a->tail->next = first;
	first->prev = stack_a->tail;
	first->next = NULL;
	stack_a->tail = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	t_node	*first;

	if (!stack_b || !stack_b->h || !stack_b->h->next)
		return ;
	first = stack_b->h;
	stack_b->h = first->next;
	stack_b->h->prev = NULL;
	stack_b->tail->next = first;
	first->prev = stack_b->tail;
	first->next = NULL;
	stack_b->tail = first;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;

	if (stack_a && stack_a->h && stack_a->h->next)
	{
		first = stack_a->h;
		stack_a->h = first->next;
		stack_a->h->prev = NULL;
		stack_a->tail->next = first;
		first->prev = stack_a->tail;
		first->next = NULL;
		stack_a->tail = first;
	}
	if (stack_b && stack_b->h && stack_b->h->next)
	{
		first = stack_b->h;
		stack_b->h = first->next;
		stack_b->h->prev = NULL;
		stack_b->tail->next = first;
		first->prev = stack_b->tail;
		first->next = NULL;
		stack_b->tail = first;
	}
	write(1, "rr\n", 3);
}
