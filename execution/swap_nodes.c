#include "../minishell.h"

void	swap_nodes(t_env **v)
{
	char	*tmp;
	char	*tmp2;

	if (!v || !(*v) || !(*v)->next)
		return ;
    // printf("key before: %s\n", (*v)->key);
	tmp = ft_strdup((*v)->next->key);
	tmp2 = ft_strdup((*v)->next->value);
	(*v)->next->key = (*v)->key;
	(*v)->next->value = (*v)->value;
	(*v)->key = tmp;
	(*v)->value = tmp2;
    // printf("key  after: %s\n", (*v)->key);
}