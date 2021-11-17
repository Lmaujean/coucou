/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:27:23 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/17 13:27:54 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_sort_3_b(t_push *push)
{
	if (!ft_stack_is_sort(push->stack_a))
		return (0);
	else if (push->stack_a->start->value < push->stack_a->start->next->value
		&& push->stack_a->start->value < push->stack_a->end->value)
	{
		ft_sb(push);
		ft_rb(push);
	}
	else if (push->stack_a->start->value > push->stack_a->start->next->value
		&& push->stack_a->start->value < push->stack_a->end->value)
		ft_sb(push);
	else if (push->stack_a->start->value < push->stack_a->start->next->value
		&& push->stack_a->start->next->value > push->stack_a->end->value)
		ft_rrb(push);
	else if (push->stack_a->start->value > push->stack_a->start->next->value
		&& push->stack_a->start->next->value < push->stack_a->end->value)
		ft_rb(push);
	else
	{
		ft_sb(push);
		ft_rrb(push);
	}
	return (0);
}