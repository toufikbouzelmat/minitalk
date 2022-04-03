/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 06:09:02 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/03/24 09:12:34 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	ft_env_to_srv(int pid, char *msg)
{
	size_t	len_msg;
	int		j;
	size_t	i;

	len_msg = ft_strlen(msg);
	i = 0;
	while (i <= len_msg)
	{
		j = 0;
		while (j < 8)
		{
			if (((msg[i] >> j) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || argv[2][0] == '\0')
	{
		write(1, "erreur\n", 7);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "pid invalid\n", 12);
		return (1);
	}
	ft_env_to_srv(pid, argv[2]);
	return (0);
}
