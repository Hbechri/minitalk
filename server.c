/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:57:12 by hbechri           #+#    #+#             */
/*   Updated: 2023/04/18 16:02:25 by hbechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int sig)
{
	static int	i;
	static char	c;

	c = c << 1 | sig;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

void	sigusr(int sign)
{
	if (sign == SIGUSR1)
		receive_bit(0);
	if (sign == SIGUSR2)
		receive_bit(1);
}

int	main(void)
{
	signal(SIGUSR1, sigusr);
	signal(SIGUSR2, sigusr);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
