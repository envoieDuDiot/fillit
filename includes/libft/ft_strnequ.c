/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:10:14 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/04 13:03:32 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t len)
{
	if (s1 && s2)
	{
		while ((s1 || s2) && len > 0)
		{
			if (ft_strncmp(s1, s2, len) == 0)
				return (1);
			else
				return (0);
			len--;
		}
	}
	return (1);
}
