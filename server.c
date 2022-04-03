/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:34:07 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/03/12 08:44:44 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	static int	stock_pid;
	static int	c;
	static int	count;

	context = NULL;
	if (!stock_pid)
		stock_pid = info->si_pid;
	if (stock_pid != info->si_pid)
	{
			c = 0;
			count = 0;
			stock_pid = 0;
	}
	sum = ft_check(sum);
	c += (sum * ft_pow(2, count++));
	if (count == 8)
	{
		ft_putchar(c);
		if (!c)
			ft_putchar('\n');
		c = 0;
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = sig_handle;
	ft_putnbr(getpid());
	ft_putchar('\n');
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
