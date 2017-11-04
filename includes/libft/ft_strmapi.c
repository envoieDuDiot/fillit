/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:53:33 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/08 20:55:37 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	char			*ptrdst;
	char			*ptrsrc;
	unsigned int	i;

	i = 0;
	ptrsrc = (char *)s;
	if (!s || !f)
		return (NULL);
	if (!(dst = malloc(ft_strlen(s) + 1)))
		return (NULL);
	ptrdst = dst;
	while (*ptrsrc)
	{
		*ptrdst = f(i, *ptrsrc);
		ptrdst++;
		ptrsrc++;
		i++;
	}
	*ptrdst = '\0';
	return (dst);
}
