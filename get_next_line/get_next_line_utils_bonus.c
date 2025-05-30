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

static size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_init_node(t_line *node, int fd)
{
	node->fd = fd;
	node->stash = NULL;
	node->next = NULL;
	node->curr = node;
}

void	ft_del_node(t_line **lst_line, int fd)
{
	t_line	*prev;
	t_line	*curr;

	if (!lst_line || !*lst_line)
		return ;
	prev = NULL;
	curr = *fd_lst;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (!prev)
				*fd_lst = curr->next;
			else
				prev->next = curr->next;
			if (curr->stash)
				free(curr->stash);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[i++])
		joined[i + j] = s1[i - 1];
	while (s2 && s2[j++])
		joined[i + j] = s2[j - 1];
	joined[i + j] = '\0';
	free(s1);
	free(s2);
	return (joined);
}

char	*ft_strchr(char *stash, char nl)
{
	size_t	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != nl && stash[i])
		i++;
	if (stash[i] == nl)
		return (stash + i);
	return (NULL);
}
