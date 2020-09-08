/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:04:44 by jcueille          #+#    #+#             */
/*   Updated: 2020/06/22 17:03:55 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	int		ft_length(char const *s, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static	int		ft_word_count(char const *s, char c, int *count)
{
	int			len;
	int			i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
			len++;
		else if (s[i] != c && s[i - 1] == c)
		{
			len++;
			(*count)++;
		}
		i++;
	}
	return (len);
}

static	char	**ft_alloc(char const *s, char c, int word_count, char **words)
{
	int			i;
	int			storage;
	char		*word;

	i = 0;
	storage = 0;
	while (storage < word_count)
	{
		if (!(word = (char *)malloc(sizeof(char) * (ft_length(s + i, c)))))
		{
			while (storage >= 0)
				free(words[storage--]);
			free(words);
			return (NULL);
		}
		words[storage++] = word;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
	}
	words[storage] = 0;
	return (words);
}

static	char	**ft_create_tab(char const *s, char c,
int word_count, char **words)
{
	int			i;
	int			index;
	int			storage;

	i = 0;
	storage = 0;
	while (storage < word_count)
	{
		while (s[i] && s[i] == c)
			i++;
		index = 0;
		while (s[i] && s[i] != c)
		{
			words[storage][index] = s[i];
			index++;
			i++;
		}
		words[storage][index] = '\0';
		storage++;
	}
	words[storage] = 0;
	return (words);
}

char			**ft_split(char const *s, char c, int *count)
{
	int			word_count;
	char		**words;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c, count);
	if (!(words = (char **)malloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	words = ft_alloc(s, c, word_count, words);
	words = ft_create_tab(s, c, word_count, words);
	return (words);
}
