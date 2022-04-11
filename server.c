/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:52:28 by atouba            #+#    #+#             */
/*   Updated: 2022/04/09 11:26:12 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long long	res;

	res = n;
	if (res >= 0 && res <= 9)
	{
		ft_putchar(res + '0');
	}
	if (res < 0)
	{
		ft_putchar('-');
		res *= -1;
		if (res >= 0 && res <= 9)
		{
			ft_putchar(res + '0');
			return ;
		}
	}
	if (res >= 10)
	{
		ft_putnbr(res / 10);
		ft_putchar((res % 10) + '0');
	}
}

int	power(int base, int n)
{
	if (n >= 1)
		return (base * power(base, n - 1));
	return (1);
}

void	ft_handler(int sig)
{
	static int	count;
	static int	n;

	if (sig == SIGUSR1)
		n += power(2, count);
	count++;
	if (count == 8)
	{
		write(1, &n, 1);
		count = 0;
		n = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}

// system("leaks server");
