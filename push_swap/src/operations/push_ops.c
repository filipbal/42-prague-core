/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:21:04 by fbalakov          #+#    #+#             */
/*   Updated: 2024/11/18 11:47:09 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *node_to_push;

    if (!stack_b || !stack_b->head)
        return ;
    node_to_push = stack_b->head;
    stack_b->head = stack_b->head->next;
    if (stack_b->head)
        stack_b->head->prev = NULL;
    else
        stack_b->tail = NULL;
    stack_b->size--;
    
    node_to_push->next = stack_a->head;
    if (stack_a->head)
        stack_a->head->prev = node_to_push;
    else
        stack_a->tail = node_to_push;
    stack_a->head = node_to_push;
    node_to_push->prev = NULL;
    stack_a->size++;
    write(1, "pa\n", 3);
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *node_to_push;

    if (!stack_a || !stack_a->head)
        return ;
    node_to_push = stack_a->head;
    stack_a->head = stack_a->head->next;
    if (stack_a->head)
        stack_a->head->prev = NULL;
    else
        stack_a->tail = NULL;
    stack_a->size--;
    
    node_to_push->next = stack_b->head;
    if (stack_b->head)
        stack_b->head->prev = node_to_push;
    else
        stack_b->tail = node_to_push;
    stack_b->head = node_to_push;
    node_to_push->prev = NULL;
    stack_b->size++;
    write(1, "pb\n", 3);
}
