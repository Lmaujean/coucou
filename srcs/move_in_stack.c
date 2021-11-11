/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:34:23 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/04 12:34:26 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

t_stack	*ft_stack_addback(t_stack *stack, int content)
{
	t_list	*list;

	if (ft_stack_empty(stack))
	{
		stack = ft_new_stack(content);
		return (stack);
	}
	list = ft_new_dlist(content);
	if (list == NULL)
		return (NULL);
	stack->end->next = list;
	list->back = stack->end;
	stack->end = list;
	stack->len++;
	return (stack);
}

t_stack	*ft_stack_addfront(t_stack *stack, int content)
{
	t_list	*list;

	if (ft_stack_empty(stack))
	{
		stack = ft_new_stack(content);
		return (stack);
	}
	list = ft_new_dlist(content);
	if (list == NULL)
		return (NULL);
	stack->start->back = list;
	list->next = stack->start;
	stack->start = list;
	stack->len++;
	return (stack);
}

t_stack	*ft_stack_delback(t_stack *stack)
{
	t_list	*temp;

	if (ft_stack_empty(stack))
		return (NULL);
	if (stack->start == stack->end)
	{
		free(stack->end);
		stack->end = NULL;
		free(stack);
		stack = NULL;
		return (stack);
	}
	temp = stack->end;
	stack->end = stack->end->back;
	stack->end->next = NULL;
	free(temp);
	temp = NULL;
	stack->len--;
	return (stack);
}

t_stack	*ft_stack_delfront(t_stack	*stack)
{
	t_list	*temp;

	if (ft_stack_empty(stack))
		return (NULL);
	if (stack->start == stack->end)
	{
		free(stack->start);
		stack->start = NULL;
		free(stack);
		stack = NULL;
		return (stack);
	}
	temp = stack->start;
	stack->start = stack->start->next;
	stack->start->back = NULL;
	free(temp);
	temp = NULL;
	stack->len--;
	return (stack);
}

int	ft_rotate_stack(t_stack *stack)
{
	t_list	*temp;

	if (ft_stack_empty(stack))
		return (1);
	if (stack->len == 1)
		return (1);
	temp = stack->start;
	stack->start = temp->next;
	stack->end->next = temp;
	stack->end = temp;
	stack->start->back = NULL;
	stack->end->next = NULL;
	return (0);
}
