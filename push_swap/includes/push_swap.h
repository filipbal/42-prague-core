/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:19:37 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/13 10:14:28 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* Error Messages */
# define ERR_MSG "Error\n"
# define ERR_MALLOC "Memory allocation failed\n"

/* Structures */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

/* ../src/main.c */
int		main(int argc, char **argv);

/* ../src/algorithm/sorting.c */
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);

/* ../src/algorithm/sorting_utils.c */
void	index_stack(t_stack *stack);
int		get_max_bits(t_stack *stack);
int		get_min_index(t_stack *stack);
void	push_min_to_b(t_stack *stack_a, t_stack *stack_b);
int		is_valid_three(t_stack *s);

/* ../src/operations/swap_ops.c */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/* ../src/operations/push_ops.c */
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);

/* ../src/operations/rotate_ops.c */
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

/* ../src/operations/rev_rotate_ops.c */
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* ../src/utils/input_parse.c */
int		check_duplicates(t_stack *stack, int value);
int		parse_arguments(int argc, char **argv, t_stack *stack_a);

/* ../src/utils/input_validation.c */
int		is_valid_integer(char *str);
long	ft_atoi_strict(const char *str);
int		is_within_limits(char *str);

/* ../src/utils/stack_ops.c */
void	stack_add_back(t_stack *stack, t_node *new_node);
int		is_sorted(t_stack *stack);

/* ../src/utils/stack_utils.c */
t_stack	*stack_init(void);
t_node	*create_node(int value);
void	stack_clear(t_stack *stack);

#endif