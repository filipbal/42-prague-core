/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:21:51 by fbalakov          #+#    #+#             */
/*   Updated: 2024/12/10 17:35:13 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	if (!s || s->size != 3 || !s->head || !s->head->next || !s->head->next->next)
		return ;
	a = s->head->value;
	b = s->head->next->value;
	c = s->head->next->next->value;
	if (a > b && b < c && a < c)
		sa(s);
	else if (a > b && b > c)
	{
		sa(s);
		rra(s);
	}
	else if (a > b && b < c && a > c)
		ra(s);
	else if (a < b && b > c && a < c)
	{
		sa(s);
		ra(s);
	}
	else if (a < b && b > c && a > c)
		rra(s);
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

static void	push_min_to_b(t_stack *stack_a, t_stack *stack_b)
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

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 4 || stack_a->size > 5)
		return ;
	while (stack_a->size > 3)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

static int	get_max_bits(t_stack *stack)
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

static void	index_stack(t_stack *stack)
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

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		size;
	int		max_bits;
	int		i;
	int		j;

	if (!stack_a || !stack_b || !stack_a->head)
		return ;
	index_stack(stack_a);
	max_bits = get_max_bits(stack_a);
	size = stack_a->size;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			current = stack_a->head;
			if (((current->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (stack_b->size != 0)
			pa(stack_a, stack_b);
	}
}
