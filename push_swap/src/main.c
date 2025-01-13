/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:20:02 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 10:45:08 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		stack_clear(stack_a);
		free(stack_a);
	}
	if (stack_b)
	{
		stack_clear(stack_b);
		free(stack_b);
	}
}

static void	init_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = stack_init();
	if (!(*stack_a))
	{
		write(2, ERR_MALLOC, 24);
		exit(1);
	}
	*stack_b = stack_init();
	if (!(*stack_b))
	{
		free(*stack_a);
		write(2, ERR_MALLOC, 24);
		exit(1);
	}
}

static void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	init_push_swap(&stack_a, &stack_b);
	if (!parse_arguments(argc, argv, stack_a))
	{
		free_stacks(stack_a, stack_b);
		write(2, ERR_MSG, 6);
		return (1);
	}
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
