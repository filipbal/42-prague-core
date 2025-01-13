/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:20:56 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 15:33:11 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack_a || !stack_a->h || !stack_a->h->next)
		return ;
	first = stack_a->h;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack_b || !stack_b->h || !stack_b->h->next)
		return ;
	first = stack_b->h;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack_a && stack_a->h && stack_a->h->next)
	{
		first = stack_a->h;
		second = first->next;
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	if (stack_b && stack_b->h && stack_b->h->next)
	{
		first = stack_b->h;
		second = first->next;
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	write(1, "ss\n", 3);
}
