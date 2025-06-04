/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:40:49 by kebris-c          #+#    #+#             */
/*   Updated: 2025/05/30 21:11:39 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t ft_strlen(const char *s)
{
    size_t len;
    
    if (!s)
        return (0);
    
    len = 0;
    while (s[len])
        len++;
    
    return (len);
}

char *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    
    if ((char)c == '\0')
        return ((char *)s);
    
    return (NULL);
}

char *ft_strdup(const char *s)
{
    char    *dup;
    size_t  len;
    size_t  i;
    
    if (!s)
        return (NULL);
    
    len = ft_strlen(s);
    dup = malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    
    i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    
    return (dup);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    char    *joined;
    size_t  len1;
    size_t  len2;
    size_t  i;
    size_t  j;
    
    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    
    joined = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!joined)
        return (NULL);
    
    i = 0;
    while (i < len1)
    {
        joined[i] = s1[i];
        i++;
    }
    
    j = 0;
    while (j < len2)
    {
        joined[i + j] = s2[j];
        j++;
    }
    
    joined[i + j] = '\0';
    
    return (joined);
}
