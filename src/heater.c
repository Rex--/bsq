/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heater.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:40:26 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 18:13:39 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"

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

void	fire_map(t_map *m, int **hm)
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
					hm[y][x] = 1;
				else
					hm[y][x] = 0;
			}
			else
				hm[y][x] = num_free_spaces(m->map[y][x], m->map[y - 1][x], \
						m->map[y][x - 1], m->map[y-1][x-1]);
			x++;
		}
		x = 0;
		y++;
	}
}

void	fire_map_p(t_map *m, int **hm)
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
					hm[y][x] = 1;
				else
					hm[y][x] = 0;
			}
			else
				hm[y][x] = (ft_min(hm[y - 1][x], hm[y][x - 1]) + 1);
			x++;
		}
		x = 0;
		y++;
	}
}

int		**make_heat_map(t_map *m)
{
	int **heat_map;
	int *first;
	int y;
	int x;

	y = 0;
	x = -1;
	heat_map = (int **)malloc((sizeof(int) * (m->lines * (m->length))) + \
		(sizeof(int *) * m->lines));
	first = (int *)(heat_map + m->lines);
	while (y < m->lines)
	{
		heat_map[y] = (first + m->length * y);
		y++;
	}
	fire_map_p(m, heat_map);
	return (heat_map);
}
