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

void    ft_search_best_move_in_a(t_push *push, int i)
{
    int stack_len;

    stack_len = push->stack_a->len;
    if (i < stack_len / 2)
    {
        ft_ra(push);
    }
    else
        ft_rra(push);
}

void    ft_medium_sort(t_push *push)
{
    int *tab;
    int j;
    int stack_len;
    int index_pivot;
    int index_pivot_stack;
    int min;

    min = ft_get_value_min(push->stack_a);
    stack_len = push->stack_a->len;
    j = 0;
    tab = ft_copy_stack(push->stack_a);
    ft_sort_tab(&tab[j], stack_len);
    index_pivot = ft_find_index_pivot(push->stack_a);
    index_pivot_stack = ft_get_index_by_value(push->stack_a, tab[index_pivot - 1]);
    while (push->stack_a)
    {
        if (min != push->stack_a->start->value && min <= index_pivot_stack)
        {
            ft_search_best_move_in_a(push, min);
        }
        ft_pb(push);
    }
    
    
    
    
    
    
    
    
    printf("mon min vaut ca dans ma stack ===> %d\n", min);
    printf("la value de mon pivot est ====> %d\n", tab[index_pivot - 1]);
    printf("l'index de mon pivot dans ma stack est ===> %d\n", index_pivot_stack);
    printf("stack_a\n");
    print_list(push->stack_a);
    printf("stack_b\n");
    print_list(push->stack_b);
    
}
