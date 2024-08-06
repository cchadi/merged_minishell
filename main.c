#include "minishell.h"

void    ignore(void)
{
    int i = 1336;

    i++;
}

t_env *env;

int main(int ac, char **ar, char **envp)
{
    t_shell *shell;
    char *input;
    t_ms *ms;

    (void)ac;
    (void)ar;
    env = NULL;
    get_envp(envp, &env);
    while(1)
    {
        input = readline("minishell $:");
        if (input != NULL && input[0] != '\0')// need this condition in a function to call it in signal handling
        {
            add_history(input);
            while (input != NULL && input[0] != '\0')
            {
                shell = NULL;
                shell = parsing(input);
                ms = ft_lstnew();
                forming_list(&ms, shell);
                execute_cmd(&ms, env, env_to_ptr(env), 0);
                free_shell(&shell);
                free_ms(&ms);
                // signal(EOF, ignore);
                // signal(SIGQUIT, exit);
                // signal(SIGINT, minishell);//need to call a function that promts the user with a new shell
                input = readline("minishell$:");
                add_history(input);
            }
        }
    }
    return (0);
}
