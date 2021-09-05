/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:22:01 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/04 12:59:12 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

void	receive_signal(int signal)
{
	static char	to_print = 0;
	static int	nb_bit = -1;

	nb_bit++;
	if (signal == SIGUSR1)
		to_print = to_print << 1;
	if (signal == SIGUSR2)
		to_print = (to_print << 1) | 1;
	if (nb_bit == 7)
	{
		ft_printf("%c", to_print);
		to_print = 0;
		nb_bit = -1;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("server PID = %d\n", pid);
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		pause();
	return (0);
}
