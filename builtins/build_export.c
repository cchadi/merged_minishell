#include "../minishell.h"

// add get_order() to print export in ascii order 

// void    get_order(t_env **v)

void    build_export(char **str, t_env **v)
{
    t_env *new;
    t_env *head;
    int i;

    i = 0;
    if (str && str[i])
    {
        while(str[i])
        {
            new = export_split(str[i], v);
            if (new != NULL)
                env_lstadd_back(v, new);
            i++;
        }
    }
    else
    {
        head = (*v);
        //get_order(v);
        while(head)
        {
            ft_putstr_fd("declare -x ", 1);
            ft_putstr_fd(head->key, 1);
            if (head->value)
            {
                ft_putchar_fd('=', 1);
                ft_putchar_fd('"', 1);
                ft_putstr_fd(head->value, 1);
                ft_putchar_fd('"', 1);
            }
            ft_putchar_fd('\n', 1);
            head = head->next;
        }
    }
    return ;
}

