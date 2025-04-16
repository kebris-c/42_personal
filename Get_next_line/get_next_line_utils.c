/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 03:15:55 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/16 04:42:29 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_line_to_stash(int fd, char *stash)
{
    char    *buffer;
    int     bytes_read;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
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

char    *get_line(char *stash)
{
    char    *line;
    char    *temp;
    char    *newline_pos;
    int     next_line_pos;

    newline_pos = ft_strchr(stash, '\n');
    if (!newline_pos)
        return (stash);
    next_line_pos = (newline_pos - stash) + 1;
    temp = ft_substr(stash, next_line_pos, );       # Modificar
    newline_pos = ft_strchr(temp, '\n');
    if (!newline_pos)
    {
        line = temp;
        free(temp);
        return (line);
    }
    line = ft_substr(temp, 0, ft_strlen(temp) - next_line_pos);
}

char    *prepare_stash(char **stash)
{
    char    *new_stash;
    char    *newline_pos;
    int     next_line_pos;

    newline_pos = ft_strchr(*stash, '\n');
    if (!newline_pos)
    {
        free(*stash);
        return (NULL);
    }
    next_line_pos = (newline_pos - stash) + 1;
    new_stash = ft_substr(stash, next_line_pos, ft_strlen(stash) - next_line_pos);
    free(stash);
    return (new_stash);
}