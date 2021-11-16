/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:38:53 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/04 12:38:54 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_stack_empty(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	return (0);
}

int	ft_size_stack(t_stack *stack)
{
	t_list	*temp;
	size_t	size;

	if (ft_stack_empty(stack))
		return (-1);
	temp = stack->start;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	ft_stack_is_sort(t_stack *stack)
{
	t_list	*temp;

	temp = NULL;
	if (ft_stack_empty(stack))
		return (-1);
	temp = stack->start;
	while (temp)
	{
		if (!temp->next)
			break ;
		if (temp->next->value < temp->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_get_value_min(t_stack *stack)
{
	int		next_value;
	int		value;
	int		pos;
	t_list	*tmp;

	pos = 1;
	value = stack->start->value;
	tmp = stack->start;
	if (tmp == NULL)
		return (1);
	while (tmp)
	{
		if (tmp->next)
		{
			next_value = tmp->next->value;
			if (value > next_value)
			{
				value = next_value;
			}
		}
		tmp = tmp->next;
		pos++;
	}
	return (value);
}

int	ft_get_value_max(t_stack *stack)
{
	int		next_value;
	int		value;
	int		pos;
	t_list	*tmp;

	pos = 1;
	value = stack->start->value;
	tmp = stack->start;
	if (tmp == NULL)
		return (1);
	while (tmp)
	{
		if (tmp->next)
		{
			next_value = tmp->next->value;
			if (value < next_value)
			{
				value = next_value;
			}
		}
		tmp = tmp->next;
		pos++;
	}
	return (value);
}
