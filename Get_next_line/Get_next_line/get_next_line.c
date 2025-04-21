/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:11:09 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/21 12:01:14 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *free_stash_buffer(char *stash, char *buffer)
{
    if (stash)
        free(stash);
	if (buffer)
		free(buffer);
    return (NULL);
}

static char	*read_and_stash(int fd, char *stash)
{
	int     bytes_read;
	char    *buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_stash_buffer(stash, buffer));
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free_stash_buffer(stash, buffer));
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	size_t	end;

	end = 0;
	if (!stash || !stash[end])
		return (NULL);
	while (stash[end] && stash[end - 1] != '\n')
		end++;
	line = (char *)malloc(sizeof(char) * end);
	if (!line)
		return (NULL);
	line = ft_substr(stash, 0, end);
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i - 1] != '\n')
		i++;
	if (!stash[i])
		return (free_stash_buffer(stash, 0));
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (free_stash_buffer(stash, 0));
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}