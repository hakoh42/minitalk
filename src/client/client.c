/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:26:30 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/04 12:58:09 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

int	ft_atoi(char *str)
{
	int		sign;
	long	i;
	long	rslt;

	i = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	rslt = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		rslt *= 10;
		rslt += str[i] - 48;
		i++;
	}
	if (rslt < 0 && sign < 0)
		rslt = -1;
	else if (rslt < 0)
		rslt = 0;
	return (sign * rslt);
}

void	send_error(char *str)
{
	ft_printf("======== ERROR =========\n%s==============\n", str);
	exit(0);
}

void	send_signals(int server_pid, char c)
{
	int	i;
	int	bl;

	i = 7;
	bl = 0;
	(void)server_pid;
	while (i > -1)
	{
		bl = c >> i & 1;
		if (!bl)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				send_error("Wrong [PID]\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				send_error("Wrong [PID]\n");
		}
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	i;

	if (ac != 3)
		send_error("Usage : ./client [SERVER_PID] [YOUR_STRING]\n");
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		send_error("Unvalid PID\n");
	i = 0;
	while (av[2][i])
	{
		send_signals(server_pid, av[2][i]);
		i++;
	}
	return (0);
}
