/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:12:14 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/03/22 02:12:17 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(const	char *str)
{
	int	i;
	int	s;
	int	nbr;

	i = 0;
	s = 1;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
		{
			s = s * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * s);
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + 48);
	if (n >= 10)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
}

int	ft_pow(int n, int j)
{
	int	i;

	if (j == 1)
		return (n);
	if (j == 0)
		return (1);
	i = n;
	while (j-- > 1)
		n = n * i;
	return (n);
}
