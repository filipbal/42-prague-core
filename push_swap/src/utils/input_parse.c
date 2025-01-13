/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:48:50 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 11:53:53 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks for duplicate values in the stack
** @param stack: Stack to check for duplicates
** @param value: New value to check against existing stack values
** @return: 1 if duplicate found, 0 if no duplicates
*/
int	check_duplicates(t_stack *stack, int value)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->head;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
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
		write(2, ERR_MSG, 6);
		if (stack)
			stack_clear(stack);
		exit(1);
	}
	value = (int)ft_atoi_strict(str);
	if (check_duplicates(stack, value))
	{
		write(2, ERR_MSG, 6);
		stack_clear(stack);
		exit(1);
	}
	new = create_node(value);
	if (!new)
	{
		write(2, ERR_MALLOC, 24);
		stack_clear(stack);
		exit(1);
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
int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		add_number_to_stack(stack_a, argv[i]);
		i++;
	}
	return (1);
}
