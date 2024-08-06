#include "../minishell.h"

int nbr_of_arg(t_arg *p)
{
    int i = 0;

    while(p)
    {
        i++;
        p = p->next;
    }
    return (i);
}
char **get_args(t_arg *p, char *cmd)
{
    char **args;
    int len;

    if (!p)
        return (NULL);
    len = nbr_of_arg(p);
    len++;
    args = malloc((len +1) * sizeof(char *));
    args[len] = NULL;
    args[0] = ft_strdup(cmd);
    len = 1;
    while(p)
    {
        args[len] = ft_strdup(p->arg);
        p = p->next;
        len++;
    }
    return (args);
}

void forming_list(t_ms **e, t_shell *shell)
{
    int i;
    t_ms *new;
    t_ms *head;

    head = (*e);
    i = 0;
    while(shell)
    {
        head->pid = i;
        head->cmd = shell->cmd;
        head->infile = shell->in;
        head->outfile = shell->out;
        head->arg = get_args(shell->args, head->cmd);
        i++;
        if (shell->next)
        {
            new = ft_lstnew();
            ft_lstadd_back(e, new);
            head = head->next;
        }
        shell = shell->next;
    }
}
