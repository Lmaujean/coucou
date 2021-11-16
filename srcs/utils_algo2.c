/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:28:37 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/08 13:28:41 by lmaujean         ###   ########.fr       */
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
    if (temp == NULL)
        return (1);
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
	return (index);
}

int ft_get_index_max(t_stack *stack)
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
    if (temp == NULL)
        return (1);
	while (temp)
	{
		if (temp->next)
		{
            next_data = temp->next->value;
            if (save < next_data)
            {
                save = next_data;
			    index = pos + 1;
            }	
		}
		temp = temp->next;
		pos++;
	}
	return (index);
}