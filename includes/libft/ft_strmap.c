/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:24:33 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/08 20:55:16 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*dst;
	char			*ptrdst;
	char			*ptrsrc;

	ptrsrc = (char *)s;
	if (!s || !f)
		return (NULL);
	if (!(dst = malloc(ft_strlen(s) + 1)))
		return (NULL);
	ptrdst = dst;
	while (*ptrsrc)
	{
		*ptrdst = f(*ptrsrc);
		ptrdst++;
		ptrsrc++;
	}
	*ptrdst = '\0';
	return (dst);
}
