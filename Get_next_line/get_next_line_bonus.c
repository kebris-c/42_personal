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

static t_fd_lst	*ft_where_is_wally(t_fd_lst **lst_head, int fd)
{
	t_fd_lst	*current;

	if (!*lst_head)
	{
		*lst_head = malloc(sizeof(t_fd_lst) * 1);
		if (!*lst_head)
			return (NULL);
		ft_init_node(*lst_head, fd);
		return (*lst_head);
	}
	current = *lst_head;
	while (current->next)
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
	static t_fd_lst	*fd_lst;
	t_fd_lst		*current;
	char			*line;
	char			*newline_ptr;
	int				check;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	current = ft_where_is_wally(&fd_lst, fd);
	if (!current)
		return (NULL);
	newline_ptr = NULL;
	check = ft_stashing(current, fd, &newline_ptr);
	if (check == -1)
	{
		ft_del_node(&fd_lst, fd);
		return (NULL);
	}
	line = ft_extract_line(current->stash, newline_ptr);
	if (!line || (!newline_ptr && !*current->stash))
	{
		ft_del_node(&fd_lst, fd);
		return (line);
	}
	current->stash = ft_update_stash(current->stash, newline_ptr);
	return (line);
}