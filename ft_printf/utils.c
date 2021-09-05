/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 22:11:07 by hakoh             #+#    #+#             */
/*   Updated: 2021/09/05 11:48:39 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr++ = 0;
		n--;
	}
}

int	ft_strlen(char *str)
{
	int					i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_is_in_str(char c, char *str)
{
	int					i;

	i = 0;
	while (str && str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	ft_nb_len(int n)
{
	long				res;
	int					len;

	len = 1;
	res = n;
	if (n < 0)
	{
		res *= -1;
		len++;
	}
	while (res > 9)
	{
		res /= 10;
		len++;
	}
	return (len);
}
