/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:21:51 by fbalakov          #+#    #+#             */
/*   Updated: 2024/11/18 11:50:54 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || !stack->head || !stack->head->next || !stack->head->next->next)
		return ;
	first = stack->head->value;
	second = stack->head->next->value;
	third = stack->head->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

static void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	i;

	min_index = get_min_index(stack_a);
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

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 4)
		return ;
	while (stack_a->size > 3)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	bits;
	int	i;
	int	j;
	int	num;

	size = stack_a->size;
	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	i = -1;
	while (++i < bits)
	{
		j = -1;
		while (++j < size)
		{
			num = stack_a->head->value;
			if ((num >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_b->size)
			pa(stack_a, stack_b);
	}
}
