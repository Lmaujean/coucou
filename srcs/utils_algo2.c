/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:28:37 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/23 13:08:15 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_get_index_min(t_stack *stack)
{
    t_list *temp;
    int		save;
	int		next_data;
	int 	index;
	int 	pos;

    temp = stack->start;
	pos = 1;
	index = 1;
	save = temp->value;
	while (temp)
	{
		if (temp->next)
		{
            next_data = temp->next->value;
            if (save > next_data)
            {
                save = next_data;
			    index = pos + 1;
            }	
		}
		temp = temp->next;
		pos++;
	}
	return (save);
}

int	ft_get_index_max(t_stack *stack)
{
	t_list	*temp;
	int		index;

	temp = stack->start;
	index = temp->index;
	while (temp)
	{
		if (temp->next && temp->next->index > index)
			index = temp->next->index;
		temp = temp->next;
	}
	return (index);
}