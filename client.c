/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:52:09 by atouba            #+#    #+#             */
/*   Updated: 2022/04/11 00:37:39 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	int	isneg(char c, int *i)
{
	if (c == '-')
	{
		*i = *i + 1;
		return (-1);
	}
	if (c == '+')
		*i = *i + 1;
	return (1);
}

static	void	initialise(int *a, unsigned long long *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 1;
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	ans;
	int					sign;
	unsigned long long	max_long;

	max_long = 9223372036854775807;
	initialise(&i, &ans, &sign);
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		|| (str[i] >= '0' && str[i] <= '9'))
	{
		sign = isneg(str[i], &i);
		while (str[i] >= '0' && str[i] <= '9')
			ans = (ans * 10 + str[i++] - '0');
	}
	if (ans >= max_long + 1 && sign == -1)
		return (0);
	if (ans >= max_long)
		return (-1);
	return (ans * sign);
}

int	main(int gc, char **gv)
{
	int	pid;
	int	i;
	int	j;
	int	k;

	k = -1;
	if (!gv[1] || !gv[2])
		exit(1);
	pid = ft_atoi(gv[1]);
	while (gv[2][++k])
	{
		i = -1;
		j = -1;
		while (++i < 8)
		{
			if (gv[2][k] & (1 << ++j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(350);
		}
	}
}

//	system("leaks client");
