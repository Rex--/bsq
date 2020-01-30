/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:04:05 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 23:32:46 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"

void	read_key(t_map *m, int fd)
{
	char *k;

	k = ft_read_line(fd);
	m->lines = ft_atoi(k);
	while (*k)
		k++;
	m->full = *--k;
	m->obstacle = *--k;
	m->empty = *--k;
}

void	read_map(t_map *m, int fd)
{
	char	*line;
	int		length;
	int		x;
	int		y;

	x = 0;
	y = 0;
	length = 0;
	line = ft_read_line(fd);
	while (line[length])
		length++;
	m->length = length;
	m->map = (char **)malloc(sizeof(char) * (m->lines * length));
	m->map[y++] = &line[0];
	while (y < m->lines)
	{
		line = ft_read_line(fd);
		m->map[y++] = line;
	}
}

int		validate_map(t_map *m)
{
	int l;
	int c;

	l = 0;
	c = 0;
	while (l < m->lines)
	{
		while (c <= m->length && m->map[l][c] != '\0')
		{
			if ((m->map[l][c] != m->empty) && (m->map[l][c] != m->obstacle))
				return (0);
			c++;
		}
		if (c != m->length)
			return (0);
		c = 0;
		l++;
	}
	if (l != (m->lines))
		return (0);
	return (1);
}

t_map	*get_map(int fd)
{
	t_map	*m;

	m = (t_map *)malloc(sizeof(t_map));
	read_key(m, fd);
	read_map(m, fd);
	if (!validate_map(m))
		return (NULL);
	return (m);
}
