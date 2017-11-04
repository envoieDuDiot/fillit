/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:10:39 by achaussa          #+#    #+#             */
/*   Updated: 2017/10/20 14:14:52 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "fcntl.h"
# include "stdlib.h"
# define BUF_SIZE 546

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	int			id;
	t_point		point[4];
}				t_tetri;

int				ch_strct(char *str);
int				ch_shrp(char *str);
int				ch_neigh(char *str);
int				ch_each(char *file, char *str, int nb_tetri);
char			*file_to_str(char*file, char *str);
void			tab_to_point(char *str, t_tetri *tetri);
void			push_up_left(t_tetri *tetri);
t_tetri			*parsing(int nb_tetri, char *file);
int				check_put(t_tetri *tetri, char **map, int max, int pos);
void			put_tetri(t_tetri *tetri, char **map, int max, int pos);
void			del_tetri(t_tetri *tetri, char **map, int max, int pos);
char			**fill_dot(char **map, int max);
int				solve(t_tetri *tetri, char **map, int max, int pos);
char			**solver(char **map, char *file, int max);
void			display(char **map, int max);

#endif
