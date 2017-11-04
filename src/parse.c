/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:04:02 by achaussa          #+#    #+#             */
/*   Updated: 2017/10/30 19:52:05 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*file_to_str(char *file, char *str)
{
	int		i;
	int		fd;
	int		ret;
	char	*buf;

	i = 0;
	if (!(buf = (char*)malloc(sizeof(char) * (546))))
		return (NULL);
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	close(fd);
	if (!(str = (char*)malloc(sizeof(char) * 546)))
		return (NULL);
	while (i < 546)
	{
		str[i] = buf[i];
		i++;
	}
	return (str);
}

void	tab_to_point(char *str, t_tetri *tetri)
{
	int i;
	int pt;

	i = 0;
	pt = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			tetri->point[pt].x = i % 5;
			tetri->point[pt].y = i / 5;
			pt++;
		}
		i++;
	}
}

void	push_up_left(t_tetri *tetri)
{
	while (tetri->point[0].y > 0 && tetri->point[1].y > 0
			&& tetri->point[2].y > 0 && tetri->point[3].y > 0)
	{
		tetri->point[0].y -= 1;
		tetri->point[1].y -= 1;
		tetri->point[2].y -= 1;
		tetri->point[3].y -= 1;
	}
	while (tetri->point[0].x > 0 && tetri->point[1].x > 0
			&& tetri->point[2].x > 0 && tetri->point[3].x > 0)
	{
		tetri->point[0].x -= 1;
		tetri->point[1].x -= 1;
		tetri->point[2].x -= 1;
		tetri->point[3].x -= 1;
	}
}

t_tetri	*parsing(int nb_tetri, char *file)
{
	int		num_t;
	char	*str;
	t_tetri *tetri;

	num_t = 0;
	str = NULL;
	if (!(tetri = malloc(sizeof(t_tetri) * (nb_tetri + 1))))
		return (NULL);
	str = file_to_str(file, str);
	while (num_t < nb_tetri)
	{
		tetri[num_t].id = num_t;
		tab_to_point(&str[num_t * 21], &tetri[num_t]);
		push_up_left(&tetri[num_t]);
		num_t++;
	}
	tetri[num_t].id = -1;
	return (tetri);
}
