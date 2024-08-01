#include "minishell.h"

int main(int ac, char **ar, char **envp)
{
    t_env *env;
    t_shell *shell;
    t_ms *ms;
    char *input;

    env = NULL;
    get_envp(envp, &env);
    input = readline("minishell $:");
    while (input != NULL)
    {
        shell = NULL;
        shell = zre3_btata_dk_lflah(input);// a function that process the input & seperate the tokens and sanitize it for after use
        //some functionalty include removing extra quotes split the words into its coresponding type if there any issue realited to these 
        //contact the writer
        ms = ft_lstnew();
        forming_list(&ms, shell);
        execute_cmd(&ms, env, envp, 0);
        input = readline("minishell$:");
    }
    // read_history(input);
    return (0);
}