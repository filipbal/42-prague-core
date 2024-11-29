/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:20:02 by fbalakov          #+#    #+#             */
/*   Updated: 2024/11/18 12:15:04 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*      
	main
	handle_error
	free_stacks		
*/

#include "../includes/push_swap.h"

void	handle_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		stack_clear(stack_a);
	if (stack_b)
		stack_clear(stack_b);
	write(2, ERR_MSG, 6);
	exit(1);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
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

static int	init_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = stack_init();
	if (!(*stack_a))
		return (write(2, ERR_MALLOC, 24));
	*stack_b = stack_init();
	if (!(*stack_b))
	{
		free(*stack_a);
		return (write(2, ERR_MALLOC, 24));
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!init_push_swap(&stack_a, &stack_b))
		return (1);
	if (!parse_arguments(argc, argv, stack_a))
	{
		free_stacks(stack_a, stack_b);
		handle_error(NULL, NULL);
	}
	if (is_sorted(stack_a) || stack_a->size < 2)
	{
		free_stacks(stack_a, stack_b);
		return (0);
	}
	if (stack_a->size == 2 && stack_a->head->value > stack_a->head->next->value)
    sa(stack_a);
	free_stacks(stack_a, stack_b);
	return (0);
}