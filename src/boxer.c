/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:48:47 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 16:40:35 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"
#include <stdio.h>

int		num_free_spaces(char fs, char t, char l, char d)
{
	int free_spaces;

	free_spaces = 1;
	if (t == fs)
		free_spaces++;
	if (l == fs)
		free_spaces++;
	if (d == fs)
		free_spaces++;
	return (free_spaces);
}

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
				int_map[y][x] = num_free_spaces(m->map[y][x], \
						m->map[y - 1][x], m->map[y][x - 1], m->map[y-1][x-1]);
			x++;
		}
		x = 0;
		y++;
	}
}

void	solve_int_map_p(t_map *m, int **im)
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
					im[y][x] = 1;
				else
					im[y][x] = 0;
			}
			else
				im[y][x] = (ft_min(im[y - 1][x], im[y][x - 1]) + 1);
			x++;
		}
		x = 0;
		y++;
	}
}

int		**make_int_map(t_map *m)
{
	int **int_map;
	int *first;
	int y;
	int x;

	y = 0;
	x = -1;
	int_map = (int **)malloc((sizeof(int) * (m->lines * (m->length))) + \
		(sizeof(int *) * m->lines));
	first = (int *)(int_map + m->lines);
	while (y < m->lines)
	{
		int_map[y] = (first + m->length * y);
		y++;
	}
	solve_int_map_p(m, int_map);
	return (int_map);
}

void	find_square(t_map *m, int **im)
{
	int y;
	int x;
	int my;
	int mx;
	int max;

	y = (m->lines - 1);
	x = (m->length - 1);
	my = 0;
	mx = 0;
	max = 1;
	while (m->map[my][mx] != m->empty)
	{
		if (mx == x)
		{
			mx = 0;
			my++;
		}
		else
			mx++;
	}
	printf("Found 1x1: (%i,%i)\n", mx, my);
	/*while (y >= 0)
	{
		while (x >= 0)
		{
			while (im[y][x] > max)
				while(im[y]
		}
	}*/
}

void	solve_map(t_map *m)
{
	int **int_map;
	int i;
	int c;

	int_map = make_int_map(m);
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
	printf("\n");
	i = 0;
	c = 0;
	while (i < m->lines)
	{
		while (c < m->length)
			printf("%i ", (int_map[i][c++] / 2));
		printf("\n");
		c = 0;
		i++;
	}
}
