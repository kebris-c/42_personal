/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:25:30 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/16 04:42:32 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_line_to_stash(int fd, char *stash);
char	*prepare_stash(char *stash);
char	*strchr(const char *s, int c);
char    *strjoin(char *s1, char *s2);
size_t	strlen(const char *s);
char    *substr(char *s, unsigned int start, size_t len);
char	*strdup(const char *s1);

#endif