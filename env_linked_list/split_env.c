#include "../minishell.h"

t_env *split_env(char *str)
{
    int i;
    int j;
    t_env	*new;
    
    new = env_lstnew();
    j = 0;
    i = 0;
    while(str[i] && str[i] != '=')
        i++;
    new->key = malloc(i+1);
    new->key[i] = '\0';
    i = 0;
    while(str[i] && str[i] != '=')
    {
        new->key[i] = str[i];
        i++;
    }
    if (str[i] == '=')
    {
        while(str[i++])
            j++;
        new->value = malloc(j);
        i = i - j;
        j = 0;
        while(str[i])
            new->value[j++] = str[i++];
        new->value[j] = '\0';
    }
    else
        new->value = NULL;
    return (new);
}