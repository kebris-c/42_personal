/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:11:09 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/17 22:07:38 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

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
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	size_t	newline_pos;
	size_t	next_line;

	newline_pos = 0;
	while (stash[newline_pos] && stash[newline_pos] != '\n')
		newline_pos++;
	if (stash[newline_pos] == '\0')
		return (stash);
	next_line = newline_pos + 1;
	line = malloc(sizeof(char) * next_line);
	line = ft_substr(stash, 0, newline_pos);
	line[next_line] = '\0';
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
	free(stash);
	return (line);
}
