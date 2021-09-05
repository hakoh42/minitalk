/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:34:22 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/03 18:51:19 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../ft_printf/libftprintf.h"

int		ft_atoi(char *str);
void	send_error(char *str);
void	send_signals(int server_pid, char c);
void	receive_signal(int signal);

#endif
