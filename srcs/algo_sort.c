/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:26:15 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/23 13:44:37 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	ft_chunk(t_stack *stack)
// {
	
// }

int	ft_get_index_by_value(t_stack *stack, int value)
{
    t_list  *tmp;
    int index;

    index = 1;
    tmp = stack->start;
    while (tmp)
    {
        if (tmp->value == value)
            return (index);
        tmp = tmp->next;
        index++;
    }
    return (-1);
}

int	ft_index_exist(t_stack *stack, int index)
{
	t_list	*temp;

	temp = stack->start;
	while (temp)
	{
		if (index == temp->index)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_push_nbr_under_pivot_to_b(t_push *push, int pivot)
{
	t_list	*temp;
	int		i;
	int		stack_len;

	i = 0;
	stack_len = push->stack_a->len;
	temp = push->stack_a->start;
	while (i < stack_len)
	{
		if (temp->index <= pivot)
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

void	ft_push_index_to_b(t_push *push, int ind)
{
	t_list	*tmp;

	tmp = push->stack_a->start;
	while (ind != tmp->index)
	{
		// printf("index = %d\n", ind);
		// printf("tmp->index = %d\n", tmp->index);
		ft_ra(push);
		tmp = push->stack_a->start;
	}
	ft_pb(push);
}

int	ft_nearer(int max, t_stack *stack_a)
{
	int	index;
	int	move = 10000000;
	int save_move;
	int save_index;
	t_list *tmp;
	int i;

	i = 0;
	while (++i < max)
	{
		tmp = stack_a->start;
		save_move = 0;
		while (tmp)
		{	
			save_move++;
			if (tmp->index == i)
			{
				save_index = tmp->index;
				if (move > save_move)
				{
					move = save_move;
					index = save_index;
				}
			}
			tmp = tmp->next;
		}
	}
	printf("%d\n", index);
	return (index);
}

void	ft_medium_sort(t_push *push)
{
	int chunk = 5;
	int package = ft_get_index_max(push->stack_a) / chunk;
	int i = 0;
	int j;
	//int max;
	
	while (i < chunk)
	{
		j = 0;
		int isset = 0;
		int value = package * (i + 1) + 1;
		while (++j < value)
		{
			if (ft_index_exist(push->stack_a, j))
				isset = 1;
		}
		j= 0;
		int leplusproche = 0;
		if (isset)
			while (leplusproche < value)
			{
				leplusproche = ft_nearer(value, push->stack_a);
				if (ft_index_exist(push->stack_a, leplusproche))
				{
					puts("stack_a");
					print_list(push->stack_a);
					puts("stack_b");
					print_list(push->stack_b);
					ft_push_index_to_b(push, leplusproche);
				}
			}
		i++;
	}
	// while (push->stack_b->len != 1)
	// {
	// 	max = ft_get_index_max(push->stack_b);
	// 	if (max != push->stack_b->start->index)
	// 		ft_rb(push);
	// 	else
	// 		ft_pa(push);
	// }
	//ft_pa(push);
	puts("stack_a");
	print_list(push->stack_a);
	puts("stack_b");
	print_list(push->stack_b);
}
