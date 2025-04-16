/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:11:09 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/16 22:01:35 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;
	int		i;
	int		j;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		i = 0;
		j = 0;
		stash = ft_strjoin(stash, buffer, i, j);
	}
	free(buffer);
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	char	*newline_pos;
	int		next_line_pos;

	newline_pos = ft_strchr(stash, '\n');
	if (!newline_pos)
		return (stash);
	next_line_pos = (newline_pos - stash) + 1;
	line = (char *)malloc(sizeof(char) * *newline_pos);
	line = ft_substr(stash, 0, '\0');
	line[next_line_pos] = '\n';
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new_stash;
	char	*newline_pos;
	int		next_line_pos;
	size_t	len;

	newline_pos = ft_strchr(stash, '\n');
	if (!newline_pos)
	{
		free(stash);
		return (NULL);
	}
	next_line_pos = (newline_pos - stash) + 1;
	len = 0;
	while (stash[len])
		len++;
	new_stash = ft_substr(stash, next_line_pos, len);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = update_stash(stash);
	return (line);
}
