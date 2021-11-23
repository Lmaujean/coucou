/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:54:45 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/23 12:52:34 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
		free(ptr);
		ptr = NULL;
	}
}

char	**ft_cpy_all_arg(char **argv)
{
	int			i;
	char		**ret;

	i = 0;
	ret = NULL;
	while (argv[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		ret[i] = ft_strdup(argv[i]);
		if (!ret[i])
			return (ret);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

t_stack	*ft_stock_arg_in_stack(char **argv)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (argv == NULL)
		return (NULL);
	while (argv[i])
	{
		temp = ft_stack_addback(temp, ft_atoi(argv[i]), 0);
		if (temp == NULL)
			return (temp);
		i++;
	}
	return (temp);
}

int	*ft_copy_stack(t_stack *src)
{
	int		stack_len;
	int		i;
	t_list	*temp;
	int		*dest;

	i = 0;
	stack_len = src->len;
	temp = src->start;
	dest = malloc(sizeof(*dest) * stack_len);
	while (i < stack_len)
	{
		dest[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (*&dest);
}

void	ft_sort_tab(int *tab, int size)
{
	int i;
    int j;
    int tmp;

    i = -1;
    while (++i < size)
    {
        j = i;
        while (++j < size)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        } 
    }
}

void	ft_create_index(t_push *push)
{
	int j;
	int *tab;
	t_list *tmp;
	
	tmp = push->stack_a->start;
	
	tab = ft_copy_stack(push->stack_a);
	ft_sort_tab(tab, push->stack_a->len);
	while (tmp)
	{
		j = 0;
		while	(j < push->stack_a->len)
		{
			if (tab[j] == tmp->value)
			{
				tmp->index = j + 1;
				break ;
			}
			j++;
		}
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_push	*push;
	char	**ret;

	push = NULL;
	ret = NULL;
	push = ft_init_stack(push);
	if (argc == 2)
		ret = ft_split(argv[1], ' ');
	else if (argc > 2)
		ret = ft_cpy_all_arg(argv + 1);
	if (ret != NULL)
	{
		if (!ft_pars(ret))
		{	
			push->stack_a = ft_stock_arg_in_stack(ret);
			// printf("stack a\n");
			// print_list(push->stack_a);
			// printf("stack b\n");
			// print_list(push->stack_b);
			ft_create_index(push);
			//print_list(push->stack_a);
			ft_sort(push);
			// printf("stack a apres move\n");
			// print_list(push->stack_a);
			// printf("stack b apres move\n");
			// print_list(push->stack_b);
		}
		else
			ft_putstr_fd("ERROR_PARSING_ARGUMENTS\n", 1);	
	}
	ft_free(ret);
	ft_clear_push(push);
	return (0);
}