/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:48:50 by fbalakov          #+#    #+#             */
/*   Updated: 2024/11/18 12:53:40 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	parse_arguments
    process_arg
    init_stacks
*/

#include "../../includes/push_swap.h"

int	check_duplicates(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	add_number_to_stack(t_stack *stack, char *str)
{
	int		value;
	t_node	*new;

	if (!is_valid_integer(str) || !is_within_limits(str))
		return (0);
	value = (int)ft_atoi_strict(str);
	if (check_duplicates(stack, value))
		return (0);
	new = create_node(value);
	if (!new)
		return (0);
	stack_add_back(stack, new);
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!add_number_to_stack(stack_a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}