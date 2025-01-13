/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:45:10 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 14:30:51 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_three(t_stack *s)
{
	if (!s || s->size != 3 || !s->head)
		return (0);
	if (!s->head->next || !s->head->next->next)
		return (0);
	return (1);
}

void	index_stack(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		index;

	if (!stack || !stack->head)
		return ;
	i = stack->head;
	while (i)
	{
		index = 0;
		j = stack->head;
		while (j)
		{
			if (j->value < i->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}

int	get_max_bits(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		bits;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	max = current->index;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

static int	get_min_index(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		index;
	int		min_index;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	min = current->value;
	index = 0;
	min_index = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	i;

	min_index = get_min_index(stack_a);
	if (min_index == -1)
		return ;
	if (min_index <= stack_a->size / 2)
	{
		i = 0;
		while (i++ < min_index)
			ra(stack_a);
	}
	else
	{
		i = 0;
		while (i++ < stack_a->size - min_index)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}
