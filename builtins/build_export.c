#include "../minishell.h"

void    get_order(t_env **v)
{
    t_env *head;
    t_env *head2;

    head = (*v);
    while(head)
    {
        head2 = head;
        while (head2)
        {
            if (head2->next && ft_strcmp(head2->key, head2->next->key) > 0)
            {
                swap_nodes(&head2);
                head2 = head;
            }
            else
                head2 = head2->next;
        }
        head = head->next;
    }
}

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
        get_order(v);
        head = (*v);
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

