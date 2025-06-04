/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:37:23 by kebris-c          #+#    #+#             */
/*   Updated: 2025/05/30 21:14:58 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Estructura simplificada - menos drama, más funcionalidad
typedef struct s_fd_node
{
    int                 fd;
    char               *stash;
    struct s_fd_node   *next;
}   t_fd_node;

static t_fd_node *find_or_create_node(t_fd_node **head, int fd)
{
    t_fd_node *current = *head;
    t_fd_node *new_node;
    
    // Buscar nodo existente
    while (current)
    {
        if (current->fd == fd)
            return (current);
        current = current->next;
    }
    
    // Crear nuevo nodo si no existe
    new_node = malloc(sizeof(t_fd_node));
    if (!new_node)
        return (NULL);
    
    new_node->fd = fd;
    new_node->stash = NULL;
    new_node->next = *head;
    *head = new_node;
    
    return (new_node);
}

static void delete_node(t_fd_node **head, int fd)
{
    t_fd_node *current = *head;
    t_fd_node *prev = NULL;
    
    while (current)
    {
        if (current->fd == fd)
        {
            if (prev)
                prev->next = current->next;
            else
                *head = current->next;
            
            free(current->stash);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

static char *extract_line(char *stash)
{
    char    *newline_pos;
    char    *line;
    int     line_len;
    int     i;
    
    if (!stash || !*stash)
        return (NULL);
    
    newline_pos = ft_strchr(stash, '\n');
    if (newline_pos)
        line_len = newline_pos - stash + 1;
    else
        line_len = ft_strlen(stash);
    
    line = malloc(sizeof(char) * (line_len + 1));
    if (!line)
        return (NULL);
    
    i = 0;
    while (i < line_len)
    {
        line[i] = stash[i];
        i++;
    }
    line[i] = '\0';
    
    return (line);
}

static char *update_stash(char *old_stash)
{
    char    *newline_pos;
    char    *new_stash;
    
    newline_pos = ft_strchr(old_stash, '\n');
    if (!newline_pos)
    {
        free(old_stash);
        return (NULL);
    }
    
    if (!(*(newline_pos + 1)))
    {
        free(old_stash);
        return (NULL);
    }
    
    new_stash = ft_strdup(newline_pos + 1);
    free(old_stash);
    return (new_stash);
}

static int read_and_stash(t_fd_node *node, int fd)
{
    char    *buffer;
    char    *temp;
    ssize_t bytes_read;
    
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (-1);
    
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buffer);
            return (-1);
        }
        
        buffer[bytes_read] = '\0';
        
        if (!node->stash)
            node->stash = ft_strdup(buffer);
        else
        {
            temp = ft_strjoin(node->stash, buffer);
            free(node->stash);
            node->stash = temp;
        }
        
        if (!node->stash)
        {
            free(buffer);
            return (-1);
        }
        
        if (ft_strchr(node->stash, '\n') || bytes_read == 0)
            break;
    }
    
    free(buffer);
    return (0);
}

char *get_next_line(int fd)
{
    static t_fd_node    *fd_list = NULL;
    t_fd_node           *current;
    char                *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    current = find_or_create_node(&fd_list, fd);
    if (!current)
        return (NULL);
    
    if (read_and_stash(current, fd) < 0)
    {
        delete_node(&fd_list, fd);
        return (NULL);
    }
    
    line = extract_line(current->stash);
    if (!line)
    {
        delete_node(&fd_list, fd);
        return (NULL);
    }
    
    current->stash = update_stash(current->stash);
    
    return (line);
}
