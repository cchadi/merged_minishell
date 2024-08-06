#include "../minishell.h"

int	simple_execute(t_ms *e, char **env)
{
	int	pid;
	
	pid = fork();
	if (pid == 0)
	{
		if (e->infile == -1 || e->outfile == -1)
			exit(0);
		if (e->infile != 0)
			dup2(e->infile, 0);
		if (e->outfile != 1)
			dup2(e->outfile, 1);
		if (execve(e->cmd, e->arg, env) == -1)
		{
			exit(0);
		}
	}
	waitpid(pid, NULL, 0);
	if (e->infile != 0)
		close(e->infile);
	if (e->outfile != 1)
		close(e->outfile);
	return (pid);
}
