/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:39:45 by kebris-c          #+#    #+#             */
/*   Updated: 2025/05/30 21:10:46 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Headers
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

// Buffer size definition
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Function prototypes
char    *get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strdup(const char *s);
size_t  ft_strlen(const char *s);

#endif
