/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:20:56 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 10:08:30 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	first = stack_a->head;
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

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	first = stack_b->head;
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

	if (stack_a && stack_a->head && stack_a->head->next)
	{
		first = stack_a->head;
		second = first->next;
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	if (stack_b && stack_b->head && stack_b->head->next)
	{
		first = stack_b->head;
		second = first->next;
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	write(1, "ss\n", 3);
}
