/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:21:51 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 08:50:54 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	if (!is_valid_three(s))
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

static void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit, int size)
{
	int	j;

	j = -1;
	while (++j < size)
	{
		if (((stack_a->head->index >> bit) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	while (stack_b->size != 0)
		pa(stack_a, stack_b);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	max_bits;
	int	i;

	if (!stack_a || !stack_b || !stack_a->head)
		return ;
	index_stack(stack_a);
	max_bits = get_max_bits(stack_a);
	size = stack_a->size;
	i = -1;
	while (++i < max_bits)
		process_bit(stack_a, stack_b, i, size);
}
