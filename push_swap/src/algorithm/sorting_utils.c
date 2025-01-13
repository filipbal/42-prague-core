/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:45:10 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 18:00:37 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Assigns sequential indexes to nodes based on value ordering
void	index_stack(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		index;

	if (!stack || !stack->h)
		return ;
	i = stack->h;
	while (i)
	{
		index = 0;
		j = stack->h;
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

// Gets number of bits needed to represent largest index
int	get_max_bits(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		bits;

	if (!stack || !stack->h)
		return (0);
	current = stack->h;
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

// Helper: Gets position of minimum value in stack
static int	get_min_index(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		index;
	int		min_index;

	if (!stack || !stack->h)
		return (-1);
	current = stack->h;
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

// Finds minimum value position, rotates stack, and pushes to stack_b
// Used by sort_five to isolate smallest values before sorting remaining 3
void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	rotations_needed;

	min_index = get_min_index(stack_a);
	if (min_index == -1)
		return ;
	if (min_index <= stack_a->size / 2)
	{
		rotations_needed = min_index;
		while (rotations_needed > 0)
		{
			ra(stack_a);
			rotations_needed--;
		}
	}
	else
	{
		rotations_needed = stack_a->size - min_index;
		while (rotations_needed > 0)
		{
			rra(stack_a);
			rotations_needed--;
		}
	}
	pb(stack_a, stack_b);
}
