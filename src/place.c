/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:02:22 by achaussa          #+#    #+#             */
/*   Updated: 2017/10/30 19:52:00 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			check_put(t_tetri *tetri, char **map, int max, int pos)
{
	int height;
	int width;
	int i;
	int j;

	i = pos / max;
	j = pos % max;
	height = i + tetri->point[3].y;
	width = j + tetri->point[3].x;
	if (height < max && width < max)
	{
		if ((((map[i + tetri->point[0].y][j + tetri->point[0].x]) == '.')
			&& ((map[i + tetri->point[1].y][j + tetri->point[1].x]) == '.')
			&& ((map[i + tetri->point[2].y][j + tetri->point[2].x]) == '.')
			&& ((map[i + tetri->point[3].y][j + tetri->point[3].x]) == '.')))
		{
			put_tetri(tetri, map, max, pos);
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}

void		put_tetri(t_tetri *tetri, char **map, int max, int pos)
{
	int i;
	int j;

	i = pos / max;
	j = pos % max;
	map[i + tetri->point[0].y][j + tetri->point[0].x] = 'A' + tetri->id;
	map[i + tetri->point[1].y][j + tetri->point[1].x] = 'A' + tetri->id;
	map[i + tetri->point[2].y][j + tetri->point[2].x] = 'A' + tetri->id;
	map[i + tetri->point[3].y][j + tetri->point[3].x] = 'A' + tetri->id;
}

void		del_tetri(t_tetri *tetri, char **map, int max, int pos)
{
	int i;
	int j;

	i = pos / max;
	j = pos % max;
	map[i + tetri->point[0].y][j + tetri->point[0].x] = '.';
	map[i + tetri->point[1].y][j + tetri->point[1].x] = '.';
	map[i + tetri->point[2].y][j + tetri->point[2].x] = '.';
	map[i + tetri->point[3].y][j + tetri->point[3].x] = '.';
}

char		**fill_dot(char **map, int max)
{
	int		i;
	int		j;

	i = 0;
	if (!(map = (char**)ft_memalloc(sizeof(char*) * max * 26)))
		return (NULL);
	while (i < max)
	{
		j = 0;
		if (!(map[i] = (char*)ft_memalloc(sizeof(char) * max * 26)))
			return (NULL);
		while (j < max)
		{
			if (map[i][j] < 65 || map[i][j] > 90)
				map[i][j] = '.';
			j++;
		}
		ft_bzero(&map[i], ft_strlen(map[i]) - j);
		i++;
	}
	return (map);
}
