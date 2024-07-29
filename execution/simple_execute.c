#include "../minishell.h"

int	simple_execute(t_ms *e, char **env)
{
	int	pid;
	pid = fork();
	if (pid == 0)
	{
		printf("here\n");
		dup2(e->infile, 0);
		close(e->infile);
		dup2(e->outfile, 1);
		close(e->outfile);

		if (execve(e->cmd, e->arg, env) == -1)
		{
			printf("erroooor\n");
			exit(0);
		}
	}
	waitpid(pid, NULL, 0);
	return (pid);
}