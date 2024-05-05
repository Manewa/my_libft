/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:54:26 by namalier          #+#    #+#             */
/*   Updated: 2023/11/13 20:25:06 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!tofind[i])
		return ((char *) str);
	while (i < n && str[i])
	{
		if (str[i] == tofind[0])
		{
			j = 0;
			while (tofind[j] && str[i + j] == tofind[j] && i + j < n)
					j++;
			if (!tofind[j])
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
