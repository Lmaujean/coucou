/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:20:26 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/04 13:20:27 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_push *push)
{
	if (!ft_reverse_stack(push->stack_a))
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_push *push)
{
	if (!ft_reverse_stack(push->stack_b))
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_push *push)
{
	ft_reverse_stack(push->stack_a);
	ft_reverse_stack(push->stack_b);
	ft_putstr_fd("rrr\n", 1);
}
