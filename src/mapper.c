/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:04:05 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/28 13:16:23 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_bsq.h"
#include <stdio.h>
#include <unistd.h>

Map		*read_map(int file)
{
	Map map;
	char *key;
	//int r;

	key = ft_read_line(file);
	printf("%s", key);
	return (&map);
}
