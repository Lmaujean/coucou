/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:54:45 by lmaujean          #+#    #+#             */
/*   Updated: 2021/10/11 15:54:49 by lmaujean         ###   ########.fr       */
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
		temp = ft_stack_addback(temp, ft_atoi(argv[i]));
		if (temp == NULL)
			return (temp);
		i++;
	}
	return (temp);
}

int	main(int argc, char **argv)
{
	t_push	*push;
	char	**ret;
	int		i;

	i = 0;
	push = NULL;
	ret = NULL;
	push = ft_init_stack(push);
	if (argc == 2)
		ret = ft_split(argv[1], ' ');
	else if (argc > 2)
		ret = ft_cpy_all_arg(argv + 1);
	if (ret != NULL)
	{
		//printf("debug print ret\n");
		//while (ret[i])
		//     printf("dans ret il y a ça ====> %s\n", ret[i++]);
		if (!ft_pars(ret))
		{
		//printf("debug print stack\n");
			
			push->stack_a = ft_stock_arg_in_stack(ret);
			//printf("mon index max est la [%d]\n", ft_get_index_max(push->stack_a));
			//printf("stack a\n");
			//print_list(push->stack_a);
			ft_sort(push);
			//printf("stack b\n");
			//print_list(push->stack_b);
			//print_list(push->stack_a);
		}
		else
			ft_putstr_fd("ERROR_PARSING_ARGUMENTS\n", 1);	
	}
	ft_free(ret);
	ft_clear_push(push);
	return (0);
}