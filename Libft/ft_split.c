/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:51:09 by namalier          #+#    #+#             */
/*   Updated: 2023/11/22 11:52:34 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int		count_word;
	size_t	i;

	i = 0;
	count_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_word++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (count_word);
}

static char	*ft_cpy_str(char *str, char const *s, size_t *i, char c)
{
	size_t	j;
	size_t	ib;

	j = 0;
	ib = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	str = malloc((*i - ib + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (ib < *i)
	{
		str[j] = s[ib];
		j++;
		ib++;
	}
	str[j] = '\0';
	return (str);
}

static void	*ft_free(char **str, char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = ft_count_word(s, c);
	while (i <= count)
	{
		free(str[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while ((int)j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_cpy_str(str[j], s, &i, c);
		if (!str[j])
			return (ft_free(str, s, c));
		while (s[i] == c)
			i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}
