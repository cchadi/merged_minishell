#include "../minishell.h"

void	check_cmd(t_ms **e, t_env *v)
{
	char *path;
	t_ms *head;

	head = (*e);
	path = env_searsh(v, "PATH");
	
	if (path)
	{
		while(head)
		{
			if (head->cmd != NULL)
				head->cmd = if_accessible(head->cmd, path);
			if (!head->cmd)
				ft_printf("%s: command not found\n", head->cmd);
			head = head->next;				
		}
	}
	free(path);
}
