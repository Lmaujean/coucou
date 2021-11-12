/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:26:15 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/12 10:26:17 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void    ft_sort_stack(t_stack *stack)
{
    t_list *temp;
    int tmp;

    temp = stack->start;
    if (ft_stack_empty(stack))
      return ;
    while (temp)
    {
        if (!temp->next)
            break ;
        if (temp->value < temp->next->value)
            temp = temp->next;
        else
        {
            tmp = temp->value;
            temp->value = temp->next->value;
            temp->next->value = tmp;
            temp = stack->start;
        }
    }
}

int ft_find_pivot(t_stack *stack)
{
    int i = stack->len / 2;
    int pivot;
    t_list *temp;

    temp = stack->start;
    while (--i)
    {
        temp = temp->next;
    }
    pivot = temp->value;
    printf("la taille de ma stack ===> %d\n", stack->len);
    printf("Mon pivot est le  ===> %d\n", pivot);
    return (pivot);
}

void    ft_push_under_pivot_to_b(t_push *push)
{
    int pivot;

    pivot = ft_find_pivot(push->stack_a);
    while (push->stack_a->start->value <= pivot)
        ft_pb(push);
    push->stack_a->start->value = push->stack_a->start->next->value - 1;
}

void    ft_push_under_pivot_to_a(t_push *push)
{
    int pivot;
    //int stack_len;
    
    //stack_len = push->stack_b->len - 1;
    pivot = ft_find_pivot(push->stack_b);
    while (push->stack_b->start->value >= pivot)
    {
         ft_pa(push);
    }
    push->stack_b->start->value = push->stack_b->start->next->value + 1;
    // if (stack_len != 5)
    // {
    //     ft_push_under_pivot_to_a(push);
    // }
    // while (!ft_stack_empty(push->stack_b))
    // {
    //     ft_pa(push);
    // }
        
}

void    ft_medium_sort(t_push *push)
{
    if (ft_stack_empty(push->stack_a))
        return ;
    if (push->stack_a)
    {
        ft_sort_stack(push->stack_a);
        ft_push_under_pivot_to_b(push);
        ft_push_under_pivot_to_a(push);
        //ft_ra(push);
        //ft_ra(push);
        //ft_ra(push);
        //ft_ra(push);
       // ft_ra(push);
    }
}