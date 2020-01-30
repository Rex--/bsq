/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:40:14 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 14:33:37 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"

int		ft_atoi(char *str)
{
	int i;
	int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

char	*ft_read_line(int fd)
{
	char	line[1000];
	char	ch;
	char	*start;
	int		r;
	int		i;

	ch = '0';
	i = 0;
	while (ch != '\n')
	{
		read(fd, &ch, 1);
		line[i++] = ch;
	}
	line[--i] = '\0';
	start = (char *)malloc(sizeof(char) * i);
	while (i > -1)
	{
		start[i] = line[i];
		i--;
	}
	return (start);
}

int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}	
