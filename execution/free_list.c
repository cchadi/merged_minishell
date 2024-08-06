#include "../minishell.h"

void    free_args(t_arg **arg)
{
    t_arg *head;
    t_arg *tmp;

    if (!arg || !(*arg))
        return ;
    head = (*arg);
    while(head)
    {
        free(head->arg);
        head = head->next;
    }
    while((*arg))
    {
        tmp = (*arg);
        (*arg) = (*arg)->next;
        free(tmp);
    }
}

void    free_shell(t_shell **shell)
{
    t_shell *tmp;

    if (!shell || !(*shell))
        return ;
    while((*shell))
    {
        tmp = (*shell);
        free((*shell)->cmd);
        free_args(&(*shell)->args);
        (*shell) = (*shell)->next;
        free(tmp);
    }
}

void    free_ms(t_ms **ms)
{
    t_ms *tmp;

    if (!ms || !(*ms))
        return ;
    while((*ms))
    {
        tmp = (*ms);
        free((*ms)->cmd);
        ft_free((*ms)->arg);
        (*ms) = (*ms)->next;
        free(tmp);
    }
}
