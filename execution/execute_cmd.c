#include "../minishell.h"

void execute_cmd(t_ms **e, t_env *v, char **envp, int tmp)
{
    int fd[2];

    if (!e || !(*e))
        return;
    while((*e))
    {
        if (execute_builtins((*e), &v) != 0)
        {
            check_cmd(e, v);
            if ((*e)->next)
            {
                pipe(fd);
                if ((*e)->infile == 0 && (*e)->pid != 0)
                {
                    if (tmp != 0)
                        (*e)->infile = tmp;
                }
                if ((*e)->outfile == 1 && (*e)->next)
                    (*e)->outfile = fd[1];
            }
            else if ((*e)->infile == 0 && (*e)->pid != 0)
                (*e)->infile = tmp;
            simple_execute((*e), envp);
            if (fd[0] > 0)
            {
                tmp = fd[0];
                close(fd[1]);
            }
        }
        (*e) = (*e)->next;
    }
}

// void execute_cmd(t_ms **e, t_env *v, char **envp, int tmp)
// {
//     int fd[2];
//     int pid;

//     if (!e || !(*e))
//         return;
//     if (execute_builtins((*e), &v) == -1)
//     {
//         check_cmd(e, v);
//         while((*e))
//         {
//             if ((*e)->next)
//             {
//                 pipe(fd);
//                 if ((*e)->infile == 0 && (*e)->pid != 0)
//                 {
//                     if (tmp != 0)
//                         (*e)->infile = tmp;
//                 }
//                 if ((*e)->outfile == 1 && (*e)->next)
//                     (*e)->outfile = fd[1];
//             }
//             else if ((*e)->infile == 0 && (*e)->pid != 0)
//                 (*e)->infile = tmp;
//             pid = simple_execute((*e), envp);
//             if (fd[0] > 0)
//             {
//                 tmp = fd[0];
//                 close(fd[1]);
//             }
//             (*e) = (*e)->next;
//         }
//         (void)pid;
//     }
// }
