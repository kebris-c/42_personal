#include "pipex.h"

static int	ft_exec_pid(t_var *var, int flag, char **argv, char **envp)
{
	t_child	*curr;
	char	*cmd;

	close(var->pip[0]);
	close(var->pip[1]);
	if (flag != 1 && flag != 2)
		return (perror("bad flag"), EXIT_FAILURE);
	if (flag == 1)
	{
		curr = &var->pid1;
		cmd = argv[2];
	}
	else
	{
		curr = &var->pid2;
		cmd = argv[3];
	}
	if (dup2(curr->in_fd, STDIN_FILENO) < 0)
		return (perror("in_fd dup2"), EXIT_FAILURE);
	close(curr->in_fd);
	if (dup2(curr->out_fd, STDOUT_FILENO) < 0)
		return (perror("out_fd dup2"), EXIT_FAILURE);
	close(curr->out_fd);
	if (execve(curr->cmd_path, cmd, envp) < 0)
		return (perror("execve"), EXIT_FAILURE);
	exit(127);
}

static int	ft_check_status(int status1, int status2)
{
	if (status1 != 0 && status2 != 0)
		return (status2);
	if (status1 == 0 && status2 != 0)
		return (status2);
	if (status1 != 0 && status2 == 0)
		return (status1);
	if (status1 == 0 && status2 == 0)
		return (status2);
}

static int	ft_wait_for_children(t_var *var)
{
	int		status1;
	int		status2;
	pid_t	wpid;

	wpid = waitpid(var->pid1.pid, &status1, 0);
	if (wpid < 0)
		return (perror("waitpid"), EXIT_FAILURE);
	if (WIFEXITED(status1))
		status1 = WEXITSTATUS(status1);
	else if (WIFSIGNALED(status1))
		status1 = WTERMSIG(status1);
	wpid = waitpid(var->pid2.pid, &status2, 0);
	if (wpid < 0)
		return (perror("waitpid"), EXIT_FAILURE);
	if (WIFEXITED(status2))
		status2 = WEXITSTATUS(status2);
	else if (WIFSIGNALED(status2))
		status2 = WTERMSIG(status2);
	return (ft_check_status(status1, status2));
}

int	ft_exec_pipeline(t_var *var, char **argv, char **envp)
{
	var->pid1.pid = fork();
	if (var->pid1.pid < 0)
		return (perror("pid1 fork"), EXIT_FAILURE);
	if (var->pid1.pid == 0)
		if (ft_exec_pid(var, 1) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	var->pid2.pid = fork();
	if (var->pid2.pid < 0)
		return (perror("pid2 fork"), EXIT_FAILURE);
	if (var->pid2.pid == 0)
		if (ft_exec_pid(var, 2, argv, envp) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	close(var->pip[0]);
	close(var->pip[1]);
	return (ft_wait_for_children(var));
}