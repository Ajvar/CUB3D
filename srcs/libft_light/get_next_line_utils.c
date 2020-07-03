/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 11:59:53 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/22 17:03:37 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"
#include "../../includes/libft_light.h"

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	int		s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (!(res = (char *)ft_calloc(len + 1, sizeof(*res))))
		return (NULL);
	if ((int)start < s_len)
		while (i < len && s[start])
			res[i++] = s[start++];
	return (res);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)))
		return (NULL);
	i = 0;
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
