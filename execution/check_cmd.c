#include "../minishell.h"

void	check_cmd(t_ms **e, t_env *v)
{
	char *path;

	path = env_searsh(v, "PATH");
	if (path)
	{
		if ((*e)->cmd != NULL)
			(*e)->cmd = if_accessible((*e)->cmd, path);

		if (!(*e)->cmd)
			ft_printf("%s: command not found\n", (*e)->cmd);
	}
}
