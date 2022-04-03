/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:11:47 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/03/22 02:11:49 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk_bonus.h"

int	g_count;

int	ft_check(int sum)
{
	if (sum == SIGUSR2)
		sum = 0;
	if (sum == SIGUSR1)
		sum = 1;
	return (sum);
}

void	sig_handle(int sum, siginfo_t *info, void *context)
{
	static char	c;
	static int	stock_pid;

	context = NULL;
	if (!stock_pid)
		stock_pid = info->si_pid;
	if (stock_pid != info->si_pid)
	{
			c = 0;
			g_count = 0;
			stock_pid = 0;
	}
	sum = ft_check(sum);
	c += (sum * ft_pow(2, g_count++));
	if (g_count == 8)
	{
		ft_putchar(c);
		if (c == '\0')
		{
			ft_putchar('\n');
			kill(info->si_pid, SIGUSR1);
		}
		c = 0;
		g_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_putnbr(getpid());
	ft_putchar('\n');
	sig.sa_sigaction = sig_handle;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
