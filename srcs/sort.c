/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:30:42 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/04 12:30:45 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_sort_3(t_push *push)
{
	if (!ft_stack_is_sort(push->stack_a))
		return (0);
	else if (push->stack_a->start->value < push->stack_a->start->next->value
		&& push->stack_a->start->value < push->stack_a->end->value)
	{
		ft_sa(push);
		ft_ra(push);
	}
	else if (push->stack_a->start->value > push->stack_a->start->next->value
		&& push->stack_a->start->value < push->stack_a->end->value)
		ft_sa(push);
	else if (push->stack_a->start->value < push->stack_a->start->next->value
		&& push->stack_a->start->next->value > push->stack_a->end->value)
		ft_rra(push);
	else if (push->stack_a->start->value > push->stack_a->start->next->value
		&& push->stack_a->start->next->value < push->stack_a->end->value)
		ft_ra(push);
	else
	{
		ft_sa(push);
		ft_rra(push);
	}
	return (0);
}

void	ft_move(t_push *push)
{
	int	min;

	min = ft_get_index_min(push->stack_a);
	while (push->stack_a->start->value != min)
		ft_rra(push);
	ft_pb(push);
}

void	ft_sort_4(t_push *push)
{
	ft_move(push);
	ft_sort_3(push);
	ft_pa(push);
}

void	ft_sort_5(t_push *push)
{
	ft_move(push);
	ft_move(push);
	ft_sort_3(push);
	ft_pa(push);
	ft_pa(push);
}

void	ft_sort(t_push *push)
{
	t_chunks *chunks;

	chunks = NULL;
	if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 2)
		ft_sa(push);
	if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 3)
		ft_sort_3(push);
	if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 4)
		ft_sort_4(push);
	if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) == 5)
		ft_sort_5(push);
	if (ft_stack_is_sort(push->stack_a) && ft_size_stack(push->stack_a) > 5)
		ft_medium_sort(push, chunks);
}
