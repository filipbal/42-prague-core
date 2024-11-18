/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:19:37 by fbalakov          #+#    #+#             */
/*   Updated: 2024/11/18 11:54:53 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* push_swap.h */
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
	int             value;
	struct s_node   *next;
	struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
	t_node  *head;
	t_node  *tail;
	int     size;
}   t_stack;

/* main.c */
int     main(int argc, char **argv);
void    handle_error(t_stack *stack_a, t_stack *stack_b);
void    free_stacks(t_stack *stack_a, t_stack *stack_b);

/* operations/swap_ops.c */
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);

/* operations/push_ops.c */
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_b, t_stack *stack_a);

/* operations/rotate_ops.c */
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);

/* operations/rev_rotate_ops.c */
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);

/* utils/input_validation.c */
int     is_valid_integer(char *str);
int     is_within_limits(char *str);
int     check_duplicates(t_stack *stack, int value);
long    ft_atoi_strict(const char *str);
int     validate_arg(char *str);

/* utils/input_parse.c */
int     parse_arguments(int argc, char **argv, t_stack *stack_a);
int     process_arg(char *arg, t_stack *stack_a);
int     init_stacks(t_stack **stack_a, t_stack **stack_b);

/* utils/stack_utils.c */
t_stack *stack_init(void);
t_node  *create_node(int value);
void    stack_clear(t_stack *stack);
int     is_empty(t_stack *stack);
int     is_sorted(t_stack *stack);

/* utils/stack_ops.c */
void    stack_add_front(t_stack *stack, t_node *new_node);
void    stack_add_back(t_stack *stack, t_node *new_node);
t_node  *stack_pop_front(t_stack *stack);
int     get_min_value(t_stack *stack);
int     get_max_value(t_stack *stack);

/* algorithm/sorting.c */
void    sort_three(t_stack *stack_a);
void    sort_five(t_stack *stack_a, t_stack *stack_b);
void    sort_large(t_stack *stack_a, t_stack *stack_b);
int     find_best_move(t_stack *stack_a, t_stack *stack_b);
void    execute_move(t_stack *stack_a, t_stack *stack_b, int move);

#endif