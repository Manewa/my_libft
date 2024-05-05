/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:33:56 by namalier          #+#    #+#             */
/*   Updated: 2023/11/21 19:19:06 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_end(char const *s1, char const *set, size_t i)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
			return (0);
		j++;
	}
	return (1);
}

static int	ft_check_start(char const *s1, char const *set, size_t i)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
			return (1);
		j++;
	}
	return (0);
}

static int	ft_count(char const *s1, char const *set, size_t i)
{
	if (i == 0)
	{
		while (s1[i] && ft_check_start(s1, set, i) == 1)
			i++;
		return (i);
	}
	else
	{
		while ((int)i >= 0 && ft_check_end(s1, set, i) == 0)
			i--;
		return (i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	end = ft_strlen(s1) - 1;
	start = ft_count(s1, set, 0);
	end = ft_count(s1, set, end);
	if (ft_check_end(s1, set, end) == 0 || s1[start] == '\0')
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
