#include "../minishell.h"

int count_env(t_env *v)
{
    int i;

    i = 0;
    while(v)
    {
        if (v->value)
            i++;
        v = v->next;
    }
    return (i);
}

char    **env_to_ptr(t_env *v)
{
    char    **ptr;
    int     i;

    i = 0;
    ptr = malloc((count_env(v) +1) * sizeof(char *));
    while(v)
    {
        if (v->value)
        {
            ptr[i] = NULL;
            ptr[i] = ft_strjoin(ptr[i], v->key);
            ptr[i] = ft_strjoin(ptr[i], "=");
            ptr[i] = ft_strjoin(ptr[i], v->value);
            i++;
        }
        v = v->next;
    }
    ptr[i] = NULL;
    return (ptr);
}
