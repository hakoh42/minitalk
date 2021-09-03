/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:18:15 by hakoh             #+#    #+#             */
/*   Updated: 2020/02/14 23:24:32 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	t_data		data;

	if (!format)
		return (0);
	ft_bzero(&data, sizeof(t_data));
	va_start(data.va, format);
	data.str = (char *)format;
	ft_parse_str(&data);
	va_end(data.va);
	return (data.buffer.b_size);
}
