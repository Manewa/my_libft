/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:53:36 by namalier          #+#    #+#             */
/*   Updated: 2023/11/13 20:19:08 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmps;

	i = 0;
	tmps = (char *)s;
	if ((char)c == 0)
		return (tmps + ft_strlen(s));
	if (!s[i])
		return (0);
	while (s[i] && s[i] != (char)c)
	{
		i++;
	}
	if (!s[i] && s[i] != (char)c)
		return (NULL);
	return ((char *)&s[i]);
}
