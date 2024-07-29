#include "../minishell.h"

char *env_searsh(t_env *v, char *find)
{
	while(v)
	{
		if (ft_strncmp(v->key, find, ft_strlen(v->key)) == 0)
			return (ft_strdup(v->value));
		v = v->next;
	}
	return (NULL);
}
