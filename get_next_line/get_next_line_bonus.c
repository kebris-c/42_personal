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

static char	*ft_update_stash(char *stash, char *newline_ptr)
{
	char	*newstash;

	if (!newline_ptr)
		return (NULL);
	newstash = ft_strjoin_and_free(NULL, newline_ptr + 1);
	free(stash);
	return (newstash);
}

static char	*ft_extract_line(char *stash, char *newline_ptr)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	if (!newline_ptr && !*stash)
	{
		line = ft_strjoin_and_free(NULL, stash);
		if (!line)
			return (NULL);
		return (line);
	}
	if (!newline_ptr)
	{
		line = ft_strjoin_and_free(NULL, stash);
		return (line);
	}
	i = newline_ptr - stash + 1;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (--i >= 0)
		line[i] = stash[i];
	return (line);
}

static int	ft_stashing(t_fd_lst *current, int fd, char **newline_ptr)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || !current)
		return (-1);
	*newline_ptr = ft_strchr(current->stash, '\n');
	bytes_read = 1;
	while (!*newline_ptr && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		buffer[bytes_read] = '\0';
		current->stash = ft_strjoin_and_free(current->stash, buffer);
		if (!current->stash)
			return (-1);
		*newline_ptr = ft_strchr(current->stash, '\n');
	}
	return (0);
}

static void	*ft_where_is_wally(t_line *lst_line, int fd)
{
	if (!lst_line)
	{
		lst_line = malloc(sizeof(t_line) * 1);
		if (!lst_line)
			return (NULL);
		ft_init_node(lst_line, fd);
		return (lst_line);
	}
	while (lst_line->curr)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current->next = malloc(sizeof(t_fd_lst) * 1);
	if (!current->next)
		return (NULL);
	current = current->next;
	ft_init_node(current, fd);
	return (current);
}

char	*get_next_line(int fd)
{
	static struct s_line	*lst_line;
	int						check;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_where_is_wally(lst_line, fd);
	if (!lst_line->curr)
		return (NULL);
	newline_ptr = NULL;
	check = ft_stashing(current, fd, &newline_ptr);
	if (check == -1)
		return (ft_del_node(&fd_lst, fd), NULL);
	line = ft_extract_line(current->stash, newline_ptr);
	if (!line || (!newline_ptr && !*current->stash))
	{
		ft_del_node(&fd_lst, fd);
		fd_lst = NULL;
		return (NULL);
	}
	current->stash = ft_update_stash(current->stash, newline_ptr);
	return (line);
}
