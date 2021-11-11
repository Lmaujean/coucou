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

void    ft_search_move(t_stack *stack, int n, void (*top)(), void (*bot)())
{
    void    (*f)();
    int  len_stack;
   
    len_stack = stack->len;
    if (len_stack == 0)
        return ;
    if (n > (len_stack / 2))
    {
        n = (len_stack - n + 1);
        f = bot;
    }
    else
    {
        n--;
        f = top;        
    }
    while (n--)
        (*f)(stack);
}

int ft_get_index(t_stack *stack)
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