#include "minishell.h"

int main(int ac, char **ar, char **envp)
{
    t_env *env;
    t_shell *shell;
    t_ms *ms;
    char *input;

    env = NULL;
    get_envp(envp, &env);
    // input = readline("minishell $:");
    input = "hello $USER backour";
    while (input != NULL)
    {
        shell = NULL;
        shell = zre3_btata_dk_lflah(input);
        ms = ft_lstnew();
        forming_list(&ms, shell);
        execute_cmd(&ms, env, envp, 0);
        // input = readline("minishell$:");
    }
    // read_history(input);
    return (0);
}