#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//	DEFINES
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//	INCLUDES
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

//	PROTOTYPES
char	*get_next_line(int fd);
void	ft_free_all(char *s1, char *s2, char *s3);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char nl);
char	*ft_strjoin_and_free(char *s1, char *s2);

#endif