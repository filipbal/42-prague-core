/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:48:00 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 15:32:55 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*last;

	if (!stack_a || !stack_a->h || !stack_a->h->next)
		return ;
	last = stack_a->tail;
	stack_a->tail = last->prev;
	stack_a->tail->next = NULL;
	last->next = stack_a->h;
	last->prev = NULL;
	stack_a->h->prev = last;
	stack_a->h = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	t_node	*last;

	if (!stack_b || !stack_b->h || !stack_b->h->next)
		return ;
	last = stack_b->tail;
	stack_b->tail = last->prev;
	stack_b->tail->next = NULL;
	last->next = stack_b->h;
	last->prev = NULL;
	stack_b->h->prev = last;
	stack_b->h = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*last;

	if (stack_a && stack_a->h && stack_a->h->next)
	{
		last = stack_a->tail;
		stack_a->tail = last->prev;
		stack_a->tail->next = NULL;
		last->next = stack_a->h;
		last->prev = NULL;
		stack_a->h->prev = last;
		stack_a->h = last;
	}
	if (stack_b && stack_b->h && stack_b->h->next)
	{
		last = stack_b->tail;
		stack_b->tail = last->prev;
		stack_b->tail->next = NULL;
		last->next = stack_b->h;
		last->prev = NULL;
		stack_b->h->prev = last;
		stack_b->h = last;
	}
	write(1, "rrr\n", 4);
}
