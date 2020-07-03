/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:27:23 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/22 16:49:02 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stddef.h>

void		*ft_calloc(size_t count, size_t size)
{
	int		i;
	void	*res;

	i = 0;
	res = NULL;
	if (!(res = malloc(count * size)))
		return (NULL);
	while (i < (int)count * (int)size)
	{
		*(char*)(res + i) = '\0';
		i++;
	}
	return (res);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	j;

	res = ft_strlen((char*)src);
	j = 0;
	if (dstsize == 0)
		return (res);
	while (j < dstsize - 1 && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (res);
}

t_map		*ft_lstlast(t_map *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

t_map		*ft_lstnew(char *content)
{
	t_map	*res;

	if ((res = malloc(sizeof(t_map))))
	{
		if (!(res->line = malloc(ft_strlen(content) + 1)))
			ft_error("Error malloc struct");
		ft_memcpy(res->line, content, ft_strlen(content) + 1);
		res->length = ft_strlen(content);
		res->next = NULL;
	}
	return (res);
}

void		ft_lstadd_back(t_map **alst, t_map *new)
{
	if (*alst)
		ft_lstlast(*alst)->next = new;
	else
		(*alst) = new;
}
