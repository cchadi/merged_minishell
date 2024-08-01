#include "../minishell.h"

void    ft_heredoc(char *del, t_ms **ms)
{
    char    *buffer;
    int     fd[2];
    int     pid;

    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        close (fd[0]);
        while (1)
        {
            buffer = readline(">");
            if (!buffer || ft_strncmp(buffer, del, sizeof(buffer)) == 0)
                break ;
            ft_putstr_fd(buffer, fd[1]);
            ft_putchar_fd('\n', fd[1]);
            if (buffer)
                free(buffer);
        }
        if (buffer)
            free(buffer);
        exit(0);
    }
    waitpid(pid, NULL, 0);
    close (fd[1]);
    dup2((*ms)->infile, fd[0]);
}
