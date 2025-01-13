/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:20:02 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 10:58:03 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    Frees memory for both stacks
    First clears all nodes in each stack
	Then frees the stack structures themselves
    Safe to call with NULL as it checks before freeing
*/
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

/*
    Allocates memory for stack structures with stack_init
    Handles allocation failures by freeing any allocated memory
*/
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

/*
	For 2 numbers: single swap if needed
    For 3 numbers: optimized sort_three algorithm
    For 4-5 numbers: sort_five algorithm using both stacks
    For larger sets: sort_large algorithm using radix sort
*/
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

/*
	Exits early if no arguments provided
	Initializes both stacks with error handling
	If input is invalid, frees memory and exits with error
	If input is not sorted, applies appropriate sorting algorithm
*/
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
