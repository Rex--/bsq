/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:48:47 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 03:45:15 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"
#include <stdio.h>

void	solve_int_map(t_map *m, int **int_map)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < m->lines)
	{
		while (x < m->length)
		{
			if (y == 0 || x == 0 || m->map[y][x] == m->obstacle)
			{
				if (m->map[y][x] == m->empty)
					int_map[y][x] = 1;
				else
					int_map[y][x] = 0;
			}
			else
				int_map[y][x] = //sum of surronding squares
		}
	}
}

int		**make_int_map(t_map *m)
{
	int **int_map;
	int *first;
	int y;
	int x;

	y = -1;
	x = -1;
	int_map = (int **)malloc((sizeof(int) * (m->lines * (m->length))) + \
		(sizeof(int *) * m->lines));
	first = (int *)(int_map + m->lines);
	while (++y < m->lines)
	{
		int_map[y] = (first + m->length * y);
		while (++x < m->length)
		{
			if (y == 0 || x == 0 || m->map[y][x] == m->obstacle)
			{
				if (m->map[y][x] == m->empty)
					int_map[y][x] = 1;
				else
					int_map[y][x] = 0;
			}
			else
				int_map[y][x] = int_map[y - 1][x - 1] + int_map[y - 1][x] + \
					int_map[y][x - 1] + 1;
		}
		x = 0;
	}
	return (int_map);
}


void	solve_map(t_map *m)
{
	int **int_map;
	int i;
	int c;
	
	i = 0;
	int_map = make_int_map(m);
	while (i < m->lines)
		printf("%s\n", m->map[i++]);
	i = 0;
	c = 0;
	while (i < m->lines)
	{
		while (c < m->length)
			printf("%i ", int_map[i][c++]);
		printf("\n");
		c = 0;
		i++;
	}
}
