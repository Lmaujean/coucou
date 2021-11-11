/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:11:45 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/08 14:11:46 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int ft_chunk_bool(t_chunks *chunks, t_list *start)
{
    if (start->value >= chunks->min && start->value <= chunks->max)
        return (1);
    return (0);
}

int ft_chunks_end(t_stack *stack, t_chunks *chunks)
{
    t_list *tmp;

    tmp = stack->start;
    while (tmp)
    {
        //printf("le debut de ma stack ===> [%d]\n", tmp->value);
        if (ft_chunk_bool(chunks, tmp))
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int ft_chunks_index(t_stack *stack, t_chunks *chunks)
{
    int pos;
    t_list *temp;

    pos = 1;
    temp = stack->start;
    while (temp)
    {
        if (ft_chunk_bool(chunks, temp))
            return (pos);
        temp = temp->next;
        pos++;
    }
    return (pos);
}

void    ft_choose_index(t_push *push, int ind1, int ind2)
{
   
    if (ind2 < ind1)
    { 
        ft_search_move(push->stack_a, ind2, &ft_ra, &ft_rra);
        ft_pb(push);
        ft_rb(push);
    }
    else
    {
        ft_search_move(push->stack_a, ind1, &ft_ra, &ft_rra);
        ft_pb(push);
    }
        
}

void    ft_push_back(t_push *push)
{
    int max;
    int count;

    max = 0;
    count = push->stack_b->len;
    while (count > 0)
    {
        max = ft_get_index(push->stack_b);
        ft_search_move(push->stack_b, max, &ft_rb, &ft_rrb);
        ft_pa(push);
        count--;
    }
}

void    ft_medium_sort(t_push *push, t_chunks *chunks)
{
    int ind1;
    int ind2;
    t_chunks next_chunks;

    chunks = ft_init_chunks(chunks);
    chunks->incr = 50;
    chunks->min = ft_get_index_min(push->stack_a);
    chunks->max = chunks->min + chunks->incr;
    while (push->stack_a->len > 0)
    {
        if (push->stack_a->len == 0)
            return ;
        next_chunks.min = chunks->min + chunks->incr;
		next_chunks.max = chunks->max + chunks->incr;
		ind1 = ft_chunks_index(push->stack_a, chunks);
		ind2 = ft_chunks_index(push->stack_a, &next_chunks); 
        printf("stack_a\n");
        print_list(push->stack_a);
        printf("stack_b\n");
        print_list(push->stack_b);
		ft_choose_index(push, ind1, ind2);
    }
    if (ft_chunks_end(push->stack_a, chunks))
    {
        printf("je suis sortie de ma boucle");
        chunks->min += chunks->incr;
        chunks->max += chunks->incr;
    }
    printf("je suis sortie de ma boucle");
    ft_push_back(push);
}