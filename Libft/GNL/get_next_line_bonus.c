/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:04:22 by namalier          #+#    #+#             */
/*   Updated: 2024/01/09 16:47:07 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_gnllen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnljoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	join = malloc((ft_gnllen(s1) + ft_gnllen(s2) + 1) * sizeof (char));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free (s1);
	return (join);
}

char	*ft_gnlchr(char *str, int to_find)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)to_find)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_gnldup(char *str)
{
	size_t	i;
	char	*dup;

	i = 0;
	if (str[i])
		dup = malloc(ft_gnllen(str) + 1 * sizeof (char));
	else
		dup = malloc(1 * sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	buf[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		nread;

	nread = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || fd > MAX_FD)
		return (NULL);
	line = ft_gnldup(buf[fd]);
	if (!line)
		return (NULL);
	if (!(ft_gnlchr(line, '\n')))
		nread = read(fd, buf[fd], BUFFER_SIZE);
	line = ft_movenewline(line, buf[fd], nread, fd);
	return (line);
}
