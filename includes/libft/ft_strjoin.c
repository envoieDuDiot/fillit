/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:23:50 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/09 12:43:02 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dst;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	if (!(dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	dst = ft_strcpy(dst, s1);
	if (!(dst = ft_strcat(dst, s2)))
		return (NULL);
	return (dst);
}
