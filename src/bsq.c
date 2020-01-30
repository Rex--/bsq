/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:00:41 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 15:28:43 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"

int	main(void)
{
	int fd;
	t_map *m;

	fd = open("maps/1-1-1.map", O_RDONLY);
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
