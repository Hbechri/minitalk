/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:57:50 by hbechri           #+#    #+#             */
/*   Updated: 2023/04/16 14:42:31 by hbechri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define RED    "\033[1m\033[31m"

int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_puterror(char *str);
void	ft_putnbr(int nb);

void	receive_bit(int sig);
void	sigusr(int sign);

int		pid_checker(char *str);
void	send_msg(int pid, char *msg);
void	send_bits(char c, int pid);

#endif