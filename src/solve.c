/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:02:07 by achaussa          #+#    #+#             */
/*   Updated: 2017/10/30 19:51:57 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "stdio.h"

int		solve(t_tetri *tetri, char **map, int max, int pos)
{
	if (tetri->id == -1)
		return (1);
	while (pos < (max * max))
	{
		if (check_put(tetri, map, max, pos))
		{
			if (solve(tetri + 1, map, max, 0))
				return (1);
			else
				del_tetri(tetri, map, max, pos);
		}
		pos++;
	}
	return (0);
}

char	**solver(char **map, char *file, int max)
{
	char	*str;
	int		nb_tetri;
	t_tetri	*tetri;

	str = NULL;
	nb_tetri = 0;
	nb_tetri = ch_each(file, str, nb_tetri);
	tetri = parsing(nb_tetri, file);
	map = fill_dot(map, max);
	while (!(solve(tetri, map, max, 0)))
	{
		free(map);
		max++;
		map = fill_dot(map, max);
	}
	return (map);
}

void	display(char **map, int max)
{
	int i;
	int j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int		max;
	char	*str;
	char	**map;

	max = 2;
	str = NULL;
	map = NULL;
	if (ac == 2)
	{
		if ((ch_each(av[1], str, 0)))
		{
			map = solver(map, av[1], max);
			max = ft_strlen(map[0]);
			display(map, max);
			free(map);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: fillit input_file\n");
	return (0);
}
