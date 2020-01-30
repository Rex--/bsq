/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:00:41 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 21:28:09 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"

int	main(int argc, char *argv[])
{
	int fd;
	int a;
	t_map *m;

	if (argc < 2)
	{
		printf("read from stdin\n");
		return (0);
	}
	a = 1;
	while (a < argc)
	{
		printf("filename: %s\n", argv[a]);
		fd = open(argv[a], O_RDONLY);
		m = get_map(fd);
		close(fd);
		if (!m)
			printf("map error");
		else
		{
			solve_map(m);
			for (int i=0;i<m->lines;i++)
				printf("%s\n", m->map[i]);
		}
		printf("\n");
		a++;
	}


	/*fd = open("maps/10-10-2.map", O_RDONLY);
	m = get_map(fd);
	close(fd);
	if (!m)
		printf("map error\n");
	else
	{
		solve_map(m);
		for (int i=0;i<m->lines;i++)
			printf("%s\n", m->map[i]);
	}*/
	return (0);
}
