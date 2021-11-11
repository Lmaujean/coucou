/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:49:18 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/04 13:49:19 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_atoi(const char *nptr)
{
	int				i;
	int				neg;
	long long		res;

	i = 0;
	while ((nptr[i] == '\t') || (nptr[i] == '\n') || (nptr[i] == '\r')
		|| (nptr[i] == '\v') || (nptr[i] == ' ') || (nptr[i] == '\f'))
		i++;
	neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if ((nptr[i + 1] == '-') || (nptr[i + 1] == '+'))
			return (0);
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	return (res * neg);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
