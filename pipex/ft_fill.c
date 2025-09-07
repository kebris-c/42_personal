#include "pipex.h"

static int	ft_resolve_path(t_var *var, int flag)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	while(var->paths[i])
	{
		if (flag == 1)
			temp = ft_strjoin(var->paths[i], var->pid1.cmd);
		else
			temp = ft_strjoin(var->paths[i], var->pid2.cmd);
		if (!temp)
			return (perror("temp ft_strjoin()"), EXIT_FAILURE);
		if (access(temp, X_OK) == 0)// success
		{
			if (flag == 1)
				var->pid1.cmd_path = temp;
			else
				var->pid2.cmd_path = temp;
			return (free(temp), EXIT_SUCCESS);
		}
		free(temp);
		i++;
	}
	return (EXIT_FAILURE);
}

static int	ft_resolve_cmd(t_var *var, char **argv)
{
	char	*temp;

	var->cmd_1 = ft_split(argv[2], ' ');
	var->cmd_2 = ft_split(argv[3], ' ');
	if (!var->cmd_1 || !var->cmd_2)
		return (perror("cmd_1/cmd_2 ft_split()"), EXIT_FAILURE);
	var->pid1.cmd = var->cmd_1[0];
	var->pid2.cmd = var->cmd_2[0];
	temp = ft_strjoin("/", var->pid1.cmd);
	if (!temp)
		return (perror("temp ft_strjoin()"), EXIT_FAILURE);
	var->pid1.cmd = ft_strdup(temp);
	free(temp);
	temp = ft_strjoin("/", var->pid2.cmd);
	if (!temp)
		return (perror("temp ft_strjoin()"), EXIT_FAILURE);
	var->pid2.cmd = ft_strdup(temp);
	return (free(temp), EXIT_SUCCESS);
}

int	ft_fill(t_var *var, char **argv, char **envp)
{
	var->pid1.in_fd = open(argv[1], O_RDONLY);
	if (var->pid1.in_fd < 0)
		return (perror("open"), EXIT_FAILURE);
	if (pipe(var->pip) < 0)
		return (perror("pipe"), EXIT_FAILURE);
	var->pid1.out_fd = var->pip[1];
	var->pid2.in_fd = var->pip[0];
	var->pid2.out_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (var->pid2.out_fd < 0)
		return (perror("open"), EXIT_FAILURE);
	if (!ft_resolve_cmd(var, argv))
		return (EXIT_FAILURE);
	while (*envp && ft_strncmp("PATH=", *envp, 5))
		envp++;
	var->paths = ft_split(*envp + 5, ':');
	if (!var->paths)
		return (perror ("paths ft_split()"), EXIT_FAILURE);
	if (!ft_resolve_path(var, 1))
		return (EXIT_FAILURE);
	if (!ft_resolve_path(var, 2))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}