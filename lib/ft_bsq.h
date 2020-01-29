/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:07:43 by rmckinno          #+#    #+#             */
/*   Updated: 2020/01/28 00:07:33 by rmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# define BUFFR_SIZE 	32768

typedef	struct			Map
{
	char	**map;
	char	empty;
	char	obstacle;
	char	full;
}						Map;

int						ft_atoi(char *str);
char					*ft_read_line(int fd);
Map						*read_map(int file);

#endif
