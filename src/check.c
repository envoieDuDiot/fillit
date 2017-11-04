/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:57:35 by gbryon            #+#    #+#             */
/*   Updated: 2017/10/30 19:52:07 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ch_strct(char *str)
{
	int	i;
	int pt;
	int line;

	i = 0;
	pt = 0;
	line = 0;
	while (str[i] && (str[i] == '.' || str[i] == '\n' || str[i] == '#')
			&& i < 20)
	{
		if (str[i] == '.' || str[i] == '#')
			pt++;
		if (str[i] == '\n')
			line++;
		i++;
	}
	if (line == 4 && pt == 16)
		return (1);
	else
		return (0);
}

int		ch_shrp(char *str)
{
	int		i;
	int		sharp;

	i = 0;
	sharp = 0;
	while (str[i] && (str[i] == '.' || str[i] == '\n' || str[i] == '#')
			&& i < 20)
	{
		if (str[i] == '#')
			sharp++;
		i++;
	}
	if (sharp == 4)
		return (1);
	else
		return (0);
}

int		ch_neigh(char *str)
{
	int		i;
	int		neighbour;

	i = 0;
	neighbour = 0;
	while (str[i] && (str[i] == '.' || str[i] == '\n' || str[i] == '#')
			&& i < 20)
	{
		if (str[i] == '#')
		{
			if (i < 22 && str[i + 1] == '#')
				neighbour++;
			if (i > 0 && str[i - 1] == '#')
				neighbour++;
			if (i < 17 && str[i + 5] == '#')
				neighbour++;
			if (i > 4 && str[i - 5] == '#')
				neighbour++;
		}
		i++;
	}
	if (neighbour >= 6 && neighbour <= 8)
		return (1);
	else
		return (0);
}

int		ch_each(char *file, char *str, int nb_tetri)
{
	int		i;

	i = 0;
	str = file_to_str(file, str);
	while (str[i] && (size_t)i < ft_strlen(str))
	{
		if (!(ch_strct(&str[i])) || !(ch_shrp(&str[i])) || !(ch_neigh(&str[i])))
			return (0);
		nb_tetri++;
		if (i >= 3 && str[i - 3] == '\n')
			return (0);
		if (str[i + 21])
		{
			i += 21;
			if (str[i] == '\n')
				i++;
		}
		else
		{
			if (str[i + 20] == '\n')
				return (0);
			return (nb_tetri);
		}
	}
	return (nb_tetri);
}
