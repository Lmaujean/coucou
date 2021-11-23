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

int     *ft_stock_group_in_tab(t_stack *stack, int pivot)
{
    t_list *temp;
    int i;
    int *dest;

    i = 0;
    temp = stack->start;
    dest = malloc(sizeof(*dest));
    while (i > pivot)
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

int ft_get_value_by_index(t_stack *stack, int value)
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
    int *tab;
    //int *tmp;
    int j;
    int index_pivot;
    int value_pivot;

    j = 0;
    tab = ft_copy_stack(push->stack_a);
    ft_sort_tab(&tab[j], push->stack_a->len);
    index_pivot = ft_find_index_pivot(push->stack_a);
    value_pivot = ft_get_value_by_index(push->stack_a, tab[index_pivot - 1]);
    printf("stack a\n");
	print_list(push->stack_a);
	printf("stack b\n");
	print_list(push->stack_b);
    ft_push_nbr_under_pivot_to_b(push, value_pivot);
    while (push->stack_b->len > 5)
    {
        printf("stack a\n");
		print_list(push->stack_a);
		printf("stack b\n");
		print_list(push->stack_b);
        tab = ft_copy_stack(push->stack_b);
        ft_sort_tab(&tab[j], push->stack_b->len);
        index_pivot = ft_find_index_pivot(push->stack_b);
        value_pivot = ft_get_value_by_index(push->stack_b, tab[index_pivot - 1]);
        //tmp = ft_stock_group_in_tab(push->stack_b, value_pivot);
        // while (j != value_pivot)
        // {
        //     printf("dans tab y'a ca ====> %d\n", tmp[j]);
        //     j++;
        // }
        ft_push_nbr_above_pivot_to_a(push, value_pivot);
    }
}
