#include "get_next_line.h"

static char	*ft_update_stash(char *stash, char *newline_ptr)
{
	int		i;
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

	if (!newline_ptr && !*stash)
	{
		line = ft_strjoin_and_free(NULL, stash);
		if (!line)
			return (ft_free_all(stash, NULL, newline_ptr), NULL);
		return (line);
	}
	if (!stash)
		return (NULL);
	i = newline_ptr - stash + 1;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (--i >= 0)
		line[i] = stash[i];
	return (line);
}

static char	*ft_stashing(int fd, char **newline_ptr)
{
	char	*buffer;
	char	*stash;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stash = NULL;
	bytes_read = 1;
	while (bytes_read > 0 && !*newline_ptr)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free_all(stash, buffer, newline_ptr), NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_and_free(stash, buffer);
		if (!stash)
			return (ft_free_all(stash, buffer, newline_ptr), NULL);
		*newline_ptr = ft_strchr(stash, '\n');
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*newline_ptr;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	newline_ptr = NULL;
	stash = ft_stashing(fd, &newline_ptr);
	if (!stash)
		return (ft_free_all(stash, NULL, newline_ptr), NULL);
	line = ft_extract_line(stash, newline_ptr);
	if (!line || (!newline_ptr && !*stash))
		return (ft_free_all(stash, NULL, newline_ptr), NULL);
	stash = ft_update_stash(stash, newline_ptr);
	return (line);
}