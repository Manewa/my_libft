/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:41:18 by namalier          #+#    #+#             */
/*   Updated: 2023/11/21 18:52:18 by natgomali        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_num(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_add_num(char *res, size_t i, int n)
{
	res[--i] = '\0';
	while (i > 0)
	{
		res[--i] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	i;
	int		count;
	char	*res;

	count = 1;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	if (n < 0)
	{
		count *= -1;
		i = 1;
		n *= -1;
	}
	i = i + 1 + ft_count_num(n);
	res = malloc(i * sizeof(char));
	if (!res)
		return (NULL);
	ft_add_num(res, i, n);
	if (count < 0)
		res[0] = '-';
	return (res);
}
