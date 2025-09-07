#ifndef PIPEX_H
# define PIPEX_H

//	HEADERS
# include "libft.h"

//	STRUCTS AND DEFS
typedef struct s_child
{
	int		in_fd;
	int		out_fd;
	char	*cmd;
	char	*cmd_path;
	pid_t	pid;
}	t_child;

typedef struct s_var
{
	int		pip[2];
	t_child	pid1;
	t_child	pid2;
	char	**cmd_1;
	char	**cmd_2;
	char	**paths;
}	t_var;

//	SRCS:
int	ft_fill(t_var *var, char **argv, char **envp);
int	ft_exec_pipeline(t_var *var, char **argv, char **envp);
