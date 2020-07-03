/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:27:15 by jcueille          #+#    #+#             */
/*   Updated: 2020/07/03 14:22:47 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int					ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (src1[i] && src2[i] && src1[i] == src2[i] && i < n - 1)
		i++;
	return (src1[i] - src2[i]);
}

char				*ft_strcpy(char *dest, char *src)
{
	int				i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void				*ft_memcpy(void *dst, const void *src, int n)
{
	int				i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!ptr_dst && !ptr_src)
		return (ptr_dst);
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (ptr_dst);
}

int					ft_pos_check(char c)
{
	char			*s;

	s = "NEWS";
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}