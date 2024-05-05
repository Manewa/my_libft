/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:01:50 by namalier          #+#    #+#             */
/*   Updated: 2023/11/21 18:51:49 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmb, size_t size)
{
	void	*str;

	if (size > 0 && nmb > SIZE_MAX / size)
		return (NULL);
	str = malloc(nmb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmb * size);
	return (str);
}
