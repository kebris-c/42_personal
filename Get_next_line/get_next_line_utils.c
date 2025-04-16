/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 03:15:55 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/16 22:01:02 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	size_t	len;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strchr(char *stash, int c)
{
	char	*s;

	s = stash;
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft_substr(char *str, int start, size_t len)
{
	char	*arr;
	int		i;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	arr = (char *)malloc((sizeof(char) * (unsigned long)len) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while ((size_t)i < len && str[start])
	{
		arr[i] = str[start];
		i++;
		start++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin(char *stash, char *buf, int i, int j)
{
	char	*str;
	size_t	stash_len;
	size_t	buffer_len;

	if (stash == NULL && buf == NULL)
		return (NULL);
	else if (stash == NULL || buf == NULL)
		return (ft_strdup(""));
	stash_len = 0;
	while (stash[stash_len])
		stash_len++;
	buffer_len = 0;
	while (buf[buffer_len])
		buffer_len++;
	str = (char *)malloc(sizeof(char) * (stash_len + buffer_len + 1));
	if (!str)
		return (NULL);
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	while (buf[j])
	{
		str[i] = buf[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}
