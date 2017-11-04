/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:11:38 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/08 14:39:17 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;
	void	*ptr;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content_size = 0;
		newlist->content = NULL;
	}
	else
	{
		if (!(ptr = malloc(content_size)))
		{
			free(newlist);
			return (NULL);
		}
		newlist->content_size = content_size;
		newlist->content = ft_memcpy(ptr, content, content_size);
	}
	newlist->next = NULL;
	return (newlist);
}
