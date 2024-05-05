/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:27:49 by namalier          #+#    #+#             */
/*   Updated: 2023/11/13 20:13:38 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	search;

	i = 0;
	tmp = (unsigned char *)s;
	search = (unsigned char)c;
	while (i < n)
	{
		if (tmp[i] == search)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
