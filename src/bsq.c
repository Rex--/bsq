/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:00:41 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 17:55:21 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"

int	main(void)
{
	int fd;
	t_map *m;

	fd = open("maps/10-10-2.map", O_RDONLY);
	m = get_map(fd);
	close(fd);
	if (!m)
		printf("map error\n");
	else
	{
		solve_map(m);
		for (int i=0;i<m->lines;i++)
			printf("%s\n", m->map[i]);
	}
	return (0);
}
