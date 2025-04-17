/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 03:15:55 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/17 22:09:59 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;

	ptr = s;
	val = (unsigned char)c;
	while (n--)
		*ptr++ = val;
	return (s);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}


static void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	arr = (void *)malloc(size * count);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * count);
	return (arr);
}

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	size_t	src_len;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	dup = malloc(sizeof(char) * (src_len + 1));
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

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_substr(char const *str, size_t start, size_t end)
{
	char	*arr;
	size_t	i;
	size_t	str_len;
	size_t	len;

	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	len = end + 1;
	if (end >= str_len)
		len = str_len + 1;
	arr = ft_calloc(sizeof(char), len);
	if (!arr)
		return (NULL);
	i = 0;
	while (end-- > 0 && str[start + i])
	{
		arr[i] = str[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	total_len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * (total_len));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
