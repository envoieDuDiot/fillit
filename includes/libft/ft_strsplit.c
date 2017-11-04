/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:32:45 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/08 21:08:15 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int		ft_word_size(char const *str)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		cpt++;
		i++;
	}
	return (cpt);
}

static int		ft_nb_word(char const *str, char c)
{
	int		i;
	int		cpt;
	int		isword;

	i = 0;
	cpt = 0;
	isword = 0;
	while (str[i])
	{
		if (str[i] != c && isword == 0)
		{
			isword = 1;
			cpt++;
		}
		if (str[i] == c)
			isword = 0;
		i++;
	}
	return (cpt);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!str || !c)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_nb_word(str, c) + 1))))
		return (NULL);
	while (str[i] && j < ft_nb_word(str, c))
	{
		while (str[i] == c && str[i])
			i++;
		if (!(tab[j] = (char*)malloc(sizeof(char) * ft_word_size(&str[i]) + 1)))
			return (NULL);
		k = 0;
		while (str[i] && str[i] != c)
			tab[j][k++] = str[i++];
		tab[j++][k] = '\0';
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
