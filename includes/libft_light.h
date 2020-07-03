/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_light.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 18:24:04 by jcueille          #+#    #+#             */
/*   Updated: 2020/07/03 14:43:14 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIGHT_H
# define LIBFT_LIGHT_H
# include <unistd.h>
# include "struct.h"

void				ft_lstadd_back(t_map **alst, t_map *new);
t_map				*ft_lstnew(char *content);
t_map				*ft_lstlast(t_map *lst);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
void				*ft_calloc(size_t count, size_t size);
int					ft_strlen(char *s);
void				ft_putstr(char *s);
int					ft_atoi(char *s);
void				*ft_memcpy(void *dst, const void *src, int n);
int					ft_strncmp(const char *s1, const char *s2, int n);
int					ft_isdigit(char *s);

#endif
