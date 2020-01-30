/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:48:47 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 21:17:30 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"

int		verify_square(int **hm, int y, int x, int max)
{
	int side;
	int cy;
	int cx;
	
	cy = y;
	cx = x;
	if (y < 0 || x < 0 || hm[y][x] < max)
		return (0);
	side = hm[y][x];
	while (cy > (y - side))
	{
		while (cx > (x - side))
		{
			if (hm[cy][cx] == 0)
			{
				hm[y][x]--;	
				return (verify_square(hm, y, x, max));
			}
			cx--;
		}
		cx = x;
		cy--;
	}
	return (1);
}

void	draw_to_map(t_map *m, int y, int x, int s)
{
	int cy;
	int cx;

	cy = y;
	cx = x;
	while (cy > (y - s))
	{
		while (cx > (x - s))
		{
			m->map[cy][cx] = m->full;
			cx--;
		}
		cx = x;
		cy--;
	}
}

void	find_from_corner(t_map *m, int **hm)
{
	int max;
	int y;
	int x;
	int my;
	int mx;

	max = 0;
	y = m->lines;
	x = m->length;
	while (--y >= 0)
	{
		while (--x >= 0)
		{	
			if (verify_square(hm, y, x, max))
			{
				max = hm[y][x];
				my = y;
				mx = x;
			}
		}
		x = m->length;;
	}
	draw_to_map(m, my, mx, max);
}

void	solve_map(t_map *m)
{
	int **heat_map;

	heat_map = make_heat_map(m);
	find_from_corner(m, heat_map);
}
