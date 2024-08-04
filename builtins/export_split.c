#include "../minishell.h"

int is_valid(char *str)
{
    int i;
    
    i = 0;
    while(str[i] && str[i] != '+' && str[i] != '=')
    {
        if (ft_isalpha(str[i]) == 1)
            i++;
        else
            return (-1);
    }
    if (str[i] == '+' && ft_isalpha(str[i-1]) == 1 && str[i+1] == '=')
        return (1);
    if (str[i] == '=' && (ft_isalpha(str[i-1]) == 1 || str[i-1] == '+'))
        return (1);
    else
        return (-1);
    return (1);
}

int    join_value(t_env **v, char *key, char *new_value)
{
    t_env *head;

    head = (*v);
    while(head)
	{
		if (ft_strncmp(head->key, key, ft_strlen(head->key)) == 0)
        {
			head->value = ft_strjoin(head->value, new_value);
            return (0);
        }
		head = head->next;
	}
	return (-1);
}

char   *take_new(char *str)
{
    int i;
    char *key;
    
    i = 0;
    while(str[i] && str[i] != '=' && str[i] != '+')
        i++;
    key = malloc(i+1);
    key[i] = '\0';
    i = 0;
    while(str[i] && str[i] != '=' && str[i] != '+')
    {
        key[i] = str[i];
        i++;
    }
    return (key);
}

char   *take_value(char *str)
{
    int i;
    int j;
    char *value;

    i = 0;
    while(str[i] && str[i] != '=')
        i++;
    if (str[i] == '=')
    {
        j = 0;
        while(str[i++])
            j++;
        value = malloc(j+1);
        value[j] = '\0';
        i = i - j;
        j = 0;
        while(str[i])
            value[j++] = str[i++];
    }
    else
        value = NULL;
    return (value);
}

t_env *export_split(char *str, t_env **v)
{
    t_env	*new;
    
    new = env_lstnew();
    if (is_valid(str) == -1)
    {
        ft_printf("export: %s: not a valid identifier\n", str);
        return (free(new), NULL);
    }
    new->key = take_new(str);
    new->value = take_value(str);
    if (ft_strchr(str, '+') != NULL)
    {
        if (join_value(v, new->key, new->value) == -1)
            return (new);
        else
            return (free(new->key), free(new->value), free(new), NULL);
    }
    return (new);
}