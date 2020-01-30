/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:07:43 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/29 23:12:29 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_map
{
	char	**map;
	char	empty;
	char	obstacle;
	char	full;
	int		lines;
	int		length;
}				t_map;
int		ft_atoi(char *str);
char	*ft_read_line(int fd);
int		ft_min(int a, int b);
void	ft_println(char *str);
t_map	*get_map(int file);
void	solve_map(t_map *m);
int		**make_heat_map(t_map *m);
#endif
