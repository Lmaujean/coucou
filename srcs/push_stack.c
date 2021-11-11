/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:19:26 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/04 13:19:28 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_push *push)
{
	if (!ft_push_stack(&push->stack_a, &push->stack_b))
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_push *push)
{
	if (!ft_push_stack(&push->stack_b, &push->stack_a))
		ft_putstr_fd("pb\n", 1);
}
