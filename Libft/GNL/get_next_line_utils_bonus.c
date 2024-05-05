/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:25:13 by namalier          #+#    #+#             */
/*   Updated: 2024/01/09 15:09:19 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_checkline(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	ft_gnlmove(char *buf, char *line, size_t stop)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buf && !line && !stop)
		return ;
	while (line[i] && line[i] != '\n')
		i++;
	if (line [i] && line[i + 1] && i == stop)
	{
		while (line[++i])
			buf[j++] = line[i];
		line[++stop] = '\0';
	}
	buf[j] = '\0';
}

char	*ft_movenewline(char *line, char *buf, ssize_t nread, int fd)
{
	char	*newline;
	int		stop;

	while (!(ft_gnlchr(line, '\n')) && nread > 0)
	{
		buf[nread] = '\0';
		line = ft_gnljoin(line, buf);
		if (!(ft_gnlchr(line, '\n')))
			nread = read(fd, buf, BUFFER_SIZE);
	}
	if (ft_gnllen(line) == 0 || nread < 0)
	{
		buf[0] = 0;
		return (free (line), NULL);
	}
	newline = ft_gnlchr(line, '\n');
	if (newline != NULL)
	{
		stop = ft_checkline(line);
		ft_gnlmove(buf, line, stop);
	}
	else
		ft_gnlmove(buf, line, ft_gnllen(line));
	return (line);
}
