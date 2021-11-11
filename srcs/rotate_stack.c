/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:21:22 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/04 13:21:23 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_push *push)
{
	if (!ft_rotate_stack(push->stack_a))
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_push *push)
{
	if (!ft_rotate_stack(push->stack_b))
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_push *push)
{
	ft_rotate_stack(push->stack_a);
	ft_rotate_stack(push->stack_b);
	ft_putstr_fd("rr\n", 1);
}
