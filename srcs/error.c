/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:56:07 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/04 12:56:12 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stringisdigit(char *tab)
{
	int	i;

	i = 0;
	if (tab[0] == '-' && ft_strlen(tab) >= 2)
		i++;
	while (tab[i])
	{
		if (!ft_isdigit(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_strissolong(char *tab)
{
	long long	value;

	value = ft_atoi(tab);
	if (ft_strlen(tab) > 11)
		return (1);
	if (value < INT_MIN || value > INT_MAX)
		return (1);
	return (0);
}

int	ft_isdoublon(char **ret)
{
	int	i;
	int	j;

	i = 0;
	while (ret[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(ret[i]) == ft_atoi(ret[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_pars(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_stringisdigit(argv[i]))
			return (1);
		if (ft_strissolong(argv[i]))
			return (1);
		i++;
	}
	if (ft_isdoublon(argv))
		return (1);
	return (0);
}
