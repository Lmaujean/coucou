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

int    *ft_copy_stack(t_stack *src)
{
    int stack_len;
    int i;
    t_list *temp;
    int *dest;

    i = 0;
    stack_len = src->len;
    temp = src->start;
    dest = malloc(sizeof(*dest) * stack_len);
    while (i < stack_len)
    {
        dest[i] = temp->value;
        temp = temp->next;
        i++;
    }
    return (*&dest);
    
}

void    ft_sort_tab(int *tab, int size)
{
    int i;
    int j;
    int tmp;

    i = -1;
    while (++i < size)
    {
        j = i;
        while (++j < size)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        } 
    }
}

int    ft_find_index_pivot(t_stack *stack)
{
    int pivot;
    int stack_len;

    stack_len = stack->len;
    pivot = stack->pivot;
    if ((stack_len / 2) % 2  == 0)
        pivot = stack_len / 2;
    else
        pivot = stack_len / 2 + 1;
    return (pivot);
}

int ft_get_index_by_value(t_stack *stack, int value)
{
    t_list  *tmp;
    int index;

    index = 1;
    tmp = stack->start;
    while (tmp)
    {
        if (tmp->value == value)
            return (value);
        tmp = tmp->next;
        index++;
    }
    return (-1);
}

void    ft_push_nbr_under_pivot_to_b(t_push *push, int pivot)
{
    t_list *temp;
    int i;
    int stack_len;

    i = 0;
    stack_len = push->stack_a->len;
    temp = push->stack_a->start;
    while (i < stack_len)
    {
        if (temp->value <= pivot)
            ft_pb(push);
        else
            ft_ra(push);
        temp = push->stack_a->start;
        i++;
    }
}

void    ft_push_nbr_above_pivot_to_a(t_push *push, int pivot)
{
    t_list *temp;
    int i;
    int stack_len;

    i = 0;
    stack_len = push->stack_b->len;
    temp = push->stack_b->start;
    while (i < stack_len)
    {
        if (temp->value >= pivot)
            ft_pa(push);
        else
            ft_rb(push);
        temp = push->stack_b->start;
        i++;
    }
}



void    ft_medium_sort(t_push *push)
{
    int *tab_a;
    int *tab_b;
    int j;
    int stack_len;
    int index_pivot_a;
    int value_pivot_a;
    int index_pivot_b;
    int value_pivot_b;


    stack_len = push->stack_a->len;
    j = 0;
    tab_a = ft_copy_stack(push->stack_a);
    ft_sort_tab(&tab_a[j], stack_len);
    index_pivot_a = ft_find_index_pivot(push->stack_a);
    value_pivot_a = ft_get_index_by_value(push->stack_a, tab_a[index_pivot_a - 1]);
    printf("l'index de mon pivot dans ma stack_a est ===> %d\n", value_pivot_a);
    ft_push_nbr_under_pivot_to_b(push, value_pivot_a);
    tab_b = ft_copy_stack(push->stack_b);
    ft_sort_tab(&tab_b[j], push->stack_b->len);
    index_pivot_b = ft_find_index_pivot(push->stack_b);
    value_pivot_b = ft_get_index_by_value(push->stack_b, tab_b[index_pivot_b - 1]);
    printf("l'index de mon pivot dans ma stack_b est ===> %d\n", value_pivot_b);
    ft_push_nbr_above_pivot_to_a(push, value_pivot_b);
    
}
