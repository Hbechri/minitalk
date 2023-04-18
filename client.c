/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:56:53 by hbechri           #+#    #+#             */
/*   Updated: 2023/04/16 15:38:07 by hbechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_checker(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] > 57 || str[i] < 48)
			return (0);
		i++;
	}
	return (1);
}

void	send_bits(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		i--;
	}
}

void	send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_bits(msg[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		ft_puterror("arguments must take : server PID + a msg to send\n");
	if (!pid_checker(av[1]))
		ft_puterror("server PID must be only digits !\n");
	pid = ft_atoi(av[1]);
	if (pid < 0)
		exit (0);
	send_msg(pid, av[2]);
}
