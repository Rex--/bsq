/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:00:41 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 23:34:39 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"

void	draw_map(t_map *m)
{
	int i;

	i = 0;
	while (i < m->lines)
		ft_println(m->map[i++]);
}

void	draw_map_from_args(int argc, char *argv[])
{
	int		fd;
	int		a;
	t_map	*m;

	a = 1;
	while (a < argc)
	{
		fd = open(argv[a], O_RDONLY);
		m = get_map(fd);
		close(fd);
		if (!m)
			ft_println("map error");
		else
		{
			solve_map(m);
			draw_map(m);
		}
		if (a < argc - 1)
			write(1, "\n", 1);
		a++;
	}
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		a;
	t_map	*m;

	a = 1;
	if (argc < 2)
	{
		m = get_map(STDIN_FILENO);
		if (!m)
			ft_println("map error");
		else
		{
			solve_map(m);
			draw_map(m);
		}
	}
	else
		draw_map_from_args(argc, argv);
	return (0);
}
