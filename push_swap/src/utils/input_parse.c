/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:48:50 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 12:54:03 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks for duplicate values in the stack
** @param stack: Stack to check for duplicates
** @param value: New value to check against existing stack values
** Exits with error message if duplicate found or stack is NULL
*/
static void	check_duplicates(t_stack *stack, int value)
{
	t_node	*current;

	if (!stack)
		error_exit();
	current = stack->head;
	while (current)
	{
		if (current->value == value)
		{
			stack_clear(stack);
			error_exit();
		}
		current = current->next;
	}
}

/*
** Error conditions handled:
** - Invalid integer format
** - Numbers outside INT range
** - Duplicate values
** - Memory allocation failures
*/
static void	add_number_to_stack(t_stack *stack, char *str)
{
	int		value;
	t_node	*new;

	if (!stack || !str || !is_valid_integer(str) || !is_within_limits(str))
	{
		if (stack)
			stack_clear(stack);
		error_exit();
	}
	value = (int)ft_atoi_strict(str);
	check_duplicates(stack, value);
	new = create_node(value);
	if (!new)
	{
		stack_clear(stack);
		error_exit();
	}
	stack_add_back(stack, new);
}

/*
** Parses and validates command line arguments into stack_a
** @param argc: Number of arguments
** @param argv: Array of argument strings
** @param stack_a: Stack to populate with validated numbers
** @return: 1 on success, 0 on any error (invalid input or memory allocation)
*/
void	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		add_number_to_stack(stack_a, argv[i]);
		i++;
	}
}
