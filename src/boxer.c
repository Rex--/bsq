/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:48:47 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 18:13:41 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"

void	find_square(t_map *m, int **hm)
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
	int **heat_map;
	int i;
	int c;

	heat_map = make_heat_map(m);
	i = 0;
	c = 0;
	while (i < m->lines)
	{
		while (c < m->length)
			printf("%i ", heat_map[i][c++]);
		printf("\n");
		c = 0;
		i++;
	}
	find_square(m, heat_map);
}
