#include "pipex.h"

static void	ft_clear_child(t_child *pid)
{
	if (pid1->in_fd)
		close(pid->in_fd);
	if (pid1->out_fd)
		close(pid->out_fd);
	if (pid->cmd)
		free(pid->cmd);
	if (pid->cmd_path)
		free(pid->cmd_path);
	if (pid->pid)
		pid->pid = 0;
	pid = NULL;
}

static void	ft_clear_var(t_var *var)
{
	if (var->pip[0])
		close(var->pip[0]);
	if (var->pip[1])
		close(var->pip[1]);
	if (var->cmd_1)
		ft_free_matrix(var->cmd_1);
	if (var->cmd_2)
		ft_free_matrix(var->cmd_2);
	if (var->paths)
		ft_free_matrix(var->paths);
	var = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	var;
	int			status;

	if (argc != 5)
		return (EXIT_FAILURE);
	if (!argv || !*argv || !envp || !*envp)
		return (EXIT_FAILURE);
	if (ft_fill(&var, argv, envp) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	status = ft_exec_pipeline(&var, argv, envp);
	if (status != 0)
		return (status);
	ft_clear_child(&var->pid1);
	ft_clear_child(&var->pid2);
	ft_clear_var(&var);
	return (EXIT_SUCCESS);
}