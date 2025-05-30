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

//	defines
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//	headers
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>

//	typedefs
typedef struct s_line
{
	int				fd;
	char			*stash;
	char			*line;
	char			*newline_ptr;
	struct s_line	*curr;
	struct s_line	*next;
}	t_line;

//	prototypes
char	*get_next_line(int fd);
void	ft_init_node(t_line *node, int fd);
void	ft_del_node(t_line **fd_line, int fd);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	*ft_strchr(char *stash, char nl);

#endif
