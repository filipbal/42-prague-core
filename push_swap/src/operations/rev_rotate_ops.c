/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:48:00 by fbalakov          #+#    #+#             */
/*   Updated: 2024/11/18 11:55:16 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    rra(t_stack *stack_a)
{
    t_node  *last;

    if (!stack_a || !stack_a->head || !stack_a->head->next)
        return ;
    last = stack_a->tail;
    stack_a->tail = last->prev;
    stack_a->tail->next = NULL;
    last->next = stack_a->head;
    last->prev = NULL;
    stack_a->head->prev = last;
    stack_a->head = last;
    write(1, "rra\n", 4);
}

void    rrb(t_stack *stack_b)
{
    t_node  *last;

    if (!stack_b || !stack_b->head || !stack_b->head->next)
        return ;
    last = stack_b->tail;
    stack_b->tail = last->prev;
    stack_b->tail->next = NULL;
    last->next = stack_b->head;
    last->prev = NULL;
    stack_b->head->prev = last;
    stack_b->head = last;
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *last;

    if (stack_a && stack_a->head && stack_a->head->next)
    {
        last = stack_a->tail;
        stack_a->tail = last->prev;
        stack_a->tail->next = NULL;
        last->next = stack_a->head;
        last->prev = NULL;
        stack_a->head->prev = last;
        stack_a->head = last;
    }
    if (stack_b && stack_b->head && stack_b->head->next)
    {
        last = stack_b->tail;
        stack_b->tail = last->prev;
        stack_b->tail->next = NULL;
        last->next = stack_b->head;
        last->prev = NULL;
        stack_b->head->prev = last;
        stack_b->head = last;
    }
    write(1, "rrr\n", 4);
}
